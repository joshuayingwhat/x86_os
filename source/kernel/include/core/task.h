#ifndef TASH_H
#define TASH_H
#include "cpu/cpu.h"
#include "comm/types.h"
#include "tools/list.h"

#define TASK_NAME_SIZE 32

#define TASK_TIME_SLICE_DEFAULT 10
// 描述进程和程序的运行
typedef struct _task_t
{
    enum
    {
        TASK_CREATED,
        TASK_RUNNING,
        TASK_SLEEP,
        TASK_READY,
        TASK_WAITTING,
    } state;

    int sleep_ticks; // 任务延迟时长
    int time_ticks;
    int slice_ticks; // 任务执行的倒计时
    char name[TASK_NAME_SIZE];
    // uint32_t *stack;
    list_node_t run_node;
    list_node_t all_node; // 所有的list
    tss_t tss;
    int tss_sel; // 保存tss选择子
} task_t;

// entry 程序入口地址 esp 栈顶指针
int task_init(task_t *task, const char *name, uint32_t entry, uint32_t esp);

// tss 切换
void task_switch_from_to(task_t *from, task_t *to);

// 添加任务管理器
typedef struct _task_manager_t
{
    task_t *currt_task;
    list_t ready_list; // 就绪队列
    list_t task_list;
    list_t sleep_list; // 任务的睡眠队列
    task_t first_task;
    task_t idle_task; //空闲进程对列
} task_manager_t;

void task_manager_init(void);
void task_first_init(void);

task_t *task_first_task(void);

void task_set_ready(task_t *task);
void task_set_block(task_t *task);
int sys_sched_yield(void);
void task_dispatch(void);
task_t *task_next_run(void);
task_t *task_current(void);
void task_time_tick(void);

void task_set_sleep(task_t *task, uint32_t ticks); // 将任务插入睡眠队列
void task_set_wakeup(task_t *task);                // 将任务从睡眠队列移除出去(到就绪对垒)
void sys_sleep(uint32_t ms);

#endif