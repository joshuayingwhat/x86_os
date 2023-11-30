#ifndef IRQ_H
#define IRQ_H

// 定义获取异常之前的栈中的信息
typedef struct _exception_frame_t
{
    // 结合压栈的过程，以及pusha指令的实际压入过程
    int gs, fs, es, ds;
    int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    // int num;
    // int error_code;
    int eip, cs, eflags;
} exception_frame_t;

// 中断和异常初始化处理程序
void irq_init(void);

// 除0异常
void do_handler_dvider(exception_frame_t *frame)
#endif