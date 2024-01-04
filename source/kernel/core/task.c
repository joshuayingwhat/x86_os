#include "core/task.h"
#include "tools/klib.h"
#include "os_cfg.h"
#include "cpu/cpu.h"
#include "tools/log.h"

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

int task_init(task_t *task, uint32_t entry, uint32_t esp)
{
    ASSERT(task != (task_t *)0);

    // tss_init(task, entry, esp);
    uint32_t *pesp = (uint32_t *)esp;
    if (pesp)
    {
        *(--pesp) = entry;
        *(--pesp) = 0;
        *(--pesp) = 0;
        *(--pesp) = 0;
        *(--pesp) = 0;
        task->stack = pesp;
    }
    return 0;
}

void simple_switch(uint32_t **from, uint32_t *to);

void task_switch_from_to(task_t *from, task_t *to)
{
    // switch_to_tss(to->tss_sel);
    simple_switch(&from->stack, to->stack);
}
