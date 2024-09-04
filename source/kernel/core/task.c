#include "core/task.h"
#include "tools/klib.h"
#include "os_cfg.h"
#include "cpu/cpu.h"
#include "tools/log.h"
#include "comm/cpu_instr.h"
#include "cpu/irq.h"

static uint32_t idle_task_stack[IDLE_TASK_SIZE];

static task_manager_t task_manager;
// 任务切换后设置另外一个程序的tss
static int tss_init(task_t *task, uint32_t entry, uint32_t esp)
{
    // 找到一个空闲的gdt描述副
    int tss_sel = gdt_alloc_des();
    if (tss_sel < 0)
    {
        // gdt表已经满了无法添加tss描述副到gdt中
        log_prinf("alloc tss failed");
        return -1;
    }

    segment_desc_set(tss_sel, (uint32_t)&task->tss, sizeof(task_t),
                     SEG_PRESENT | SEG_DPL0 | SEG_TYPE_TSS);

    kernel_memset(&task->tss, 0, sizeof(tss_t));

    task->tss.eip = entry;
    task->tss.esp = task->tss.esp0 = esp;
    task->tss.ss = task->tss.ss0 = KERNEL_SELECTOR_DS;
    task->tss.es = task->tss.ds = task->tss.fs = task->tss.gs = KERNEL_SELECTOR_DS;
    task->tss.cs = KERNEL_SELECTOR_CS;
    task->tss.eflags = EFLAGS_IF | EFLAGS_DEFALUT;
    task->tss_sel = tss_sel; // 将tss选择子保存到tss_sel中
    return 0;
}

int task_init(task_t *task, const char *name, uint32_t entry, uint32_t esp)
{
    ASSERT(task != (task_t *)0);
    tss_init(task, entry, esp);
    // 复制进程名到task.name中
    kernel_strncpy(task->name, name, TASK_NAME_SIZE);
    task->state = TASK_CREATED; // 将开始创建的进程状态设置成task_created
    task->sleep_ticks = 0;      // 初始化任务延迟时间
    task->time_ticks = TASK_TIME_SLICE_DEFAULT;
    task->slice_ticks = task->time_ticks;

    list_node_init(&task->all_node);
    list_node_init(&task->run_node);

    // 将进程插入到就绪队列中
    irq_state_t state = irq_enter_protection();
    task_set_ready(task);
    list_insert_last(&task_manager.task_list, &task->all_node);
    irq_leave_protection(state);
    return 0;
}

void simple_switch(uint32_t **from, uint32_t *to);

void task_switch_from_to(task_t *from, task_t *to)
{
    switch_to_tss(to->tss_sel);
    // simple_switch(&from->stack, to->stack);
}

// 空闲进程的代码,在整个系统都不需要cpu运行的时候这个空闲进程才运行
static void idle_task_entry(void)
{
    for (;;)
    {
        hlt(); // 执行低功耗指令
    }
}

void task_manager_init(void)
{
    list_init(&task_manager.ready_list);
    list_init(&task_manager.task_list);
    list_init(&task_manager.sleep_list);
    task_manager.currt_task = (task_t *)0;

    task_init(&task_manager.idle_task, "idle_task", (uint32_t)idle_task_entry, (uint32_t)(idle_task_stack + IDLE_TASK_SIZE));
}

void task_first_init(void)
{
    task_init(&task_manager.first_task, "first task", 0, 0); //??为什么入口设置为0，堆栈也设置为0
    write_tr(task_manager.first_task.tss_sel);
    task_manager.currt_task = &task_manager.first_task;
}

task_t *task_first_task(void)
{
    return &task_manager.first_task;
}

void task_set_ready(task_t *task)
{
    // 如果是空闲进程就直接返回不插入到就绪队列不然空闲进程也会运行
    if (task == &task_manager.idle_task)
    {
        return;
    }
    list_insert_last(&task_manager.ready_list, &task->run_node);
    task->state = TASK_READY;
}
// 将任务从就绪队列中移除 此时任务的状态不确定 有可能是等待 有可能是睡眠因此不设置状态置
void task_set_block(task_t *task)
{
    if (task == &task_manager.idle_task)
    {
        return;
    }
    list_remove(&task_manager.ready_list, &task->run_node);
}

task_t *task_current(void)
{
    return task_manager.currt_task;
}

int sys_sched_yield()
{
    irq_state_t state = irq_enter_protection();
    if (list_count(&task_manager.ready_list) > 1)
    {
        // 如果就绪队列中有其他的任务则将头部任务移到尾部
        task_t *current_task = task_current();
        // 从队列头部取出当前任务
        task_set_block(current_task);
        // 将当前任务添加到队列尾部
        task_set_ready(current_task);
        // 将cpu的使用权让给下一个任务
        task_dispatch();
    }
    irq_leave_protection(state);
    // 没有其他的任务了就直接返回
    return 0;
}

task_t *task_next_run(void)
{
    if (list_count(&task_manager.ready_list) == 0)
    {
        // 将空闲进程放入接下来要执行的任务队列
        return &task_manager.idle_task;
    }
    list_node_t *task_node = list_first(&task_manager.ready_list);
    return list_node_parent(task_node, task_t, run_node);
}

void task_dispatch(void)
{
    // irq_state_t state = irq_enter_protection();
    task_t *to = task_next_run();
    if (to != task_manager.currt_task)
    {
        task_t *from = task_current();
        task_manager.currt_task = to;
        to->state = TASK_RUNNING;
        task_switch_from_to(from, to);
    }
    // irq_leave_protection(state);
}
// 当时间片到了之后将运行中队列中当前的任务移到队列尾部
// 并取出运行队列中的下一个任务
void task_time_tick(void)
{
    task_t *current_task = task_current();
    // irq_state_t state = irq_enter_protection();
    // 当前任务的运行时间片已经为0了
    if (--current_task->slice_ticks == 0)
    {
        // 将这次的任务重新设置计数
        current_task->slice_ticks = current_task->time_ticks;
        task_set_block(current_task);
        task_set_ready(current_task);
        task_dispatch();
    }
    list_node_t *curr = list_first(&task_manager.sleep_list);
    // 如果当前节点有效不为空
    while (curr)
    {
        list_node_t *next = list_node_next(curr);
        task_t *task = list_node_parent(curr, task_t, run_node);
        if (--task->sleep_ticks == 0)
        {
            task_set_wakeup(task);
            task_set_ready(task);
        }
        curr = next;
    }
    task_dispatch();
    // irq_leave_protection(state);
}

// 将任务插入睡眠队列
void task_set_sleep(task_t *task, uint32_t ticks)
{
    if (ticks == 0)
    {
        return; // 如果当前任务不需要睡眠则直接返回
    }
    task->sleep_ticks = ticks;
    task->state = TASK_SLEEP;
    list_insert_last(&task_manager.sleep_list, &task->run_node);
}

// 将任务从睡眠队列移除出去(到就绪对垒)
void task_set_wakeup(task_t *task)
{
    list_remove(&task_manager.sleep_list, &task->run_node);
}
void sys_sleep(uint32_t ms)
{
    irq_state_t state = irq_enter_protection();
    task_set_block(task_manager.currt_task); // 将当前进程从队列中移除
    task_set_sleep(task_manager.currt_task, (ms + (OS_TICKS_MS - 1)) / OS_TICKS_MS);
    task_dispatch();
    irq_leave_protection(state);
}
