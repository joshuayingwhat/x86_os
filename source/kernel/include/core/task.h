#ifndef TASH_H
#define TASH_H
#include "cpu/cpu.h"
#include "comm/types.h"

// 描述进程和程序的运行
typedef struct _task_t
{
    tss_t tss;
    int tss_sel; // 保存tss选择子
} task_t;

// entry 程序入口地址 esp 栈顶指针
int task_init(task_t *task, uint32_t entry, uint32_t esp);

// tss 切换
void task_switch_from_to(task_t *from, task_t *to);
#endif