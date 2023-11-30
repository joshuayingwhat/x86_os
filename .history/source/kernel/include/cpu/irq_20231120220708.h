#ifndef IRQ_H
#define IRQ_H

#define IRQ0_DE 0
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

typedef void (*irq_handler_t)(exception_frame_t *frame);

// 中断和异常初始化处理程序
void irq_init(void);

// 除0异常
void exception_handle_divider(void);

int irq_install(int irq_num, irq_handler_t handler)
#endif