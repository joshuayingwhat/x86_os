#ifndef IRQ_H
#define IRQ_H

// 中断号
#define IRQ0_DE 0
#define IRQ1_DB 1
#define IRQ2_NMI 2
#define IRQ3_BP 3
#define IRQ4_OF 4
#define IRQ5_BR 5
#define IRQ6_UD 6
#define IRQ7_NM 7
#define IRQ8_DF 8
#define IRQ10_TS 10
#define IRQ11_NP 11
#define IRQ12_SS 12
#define IRQ13_GP 13
#define IRQ14_PF 14
#define IRQ16_MF 16
#define IRQ17_AC 17
#define IRQ18_MC 18
#define IRQ19_XM 19
#define IRQ20_VE 20

// 定义获取异常之前的栈中的信息
typedef struct _exception_frame_t
{
    // 结合压栈的过程，以及pusha指令的实际压入过程
    int gs, fs, es, ds;
    int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    int num;
    int error_code;
    int eip, cs, eflags;
} exception_frame_t;

typedef void (*irq_handler_t)(exception_frame_t *frame);

// 中断和异常初始化处理程序
void irq_init(void);

// 除0异常 等各种异常
void exception_handle_divider(void);
void exception_handler_Debug(void);
void exception_handler_NMI(void);
void exception_handler_breakpoint(void);
void exception_handler_overflow(void);
void exception_handler_bound_range(void);
void exception_handler_invalid_opcode(void);
void exception_handler device_unavailable(void);
void exception_handler double_fault(void);
void exception_handler invalid_tss(void);
void exception_handler segment_not_present(void);
void exception_handler stack_segment_fault(void);
void exception_handler general_protection(void);
void exception_handler page_fault(void);
void exception_handler fpu_error(void);
void exception_handler alignment_check(void);
void exception_handler machine_check(void);
void exception_handler smd_exception(void);
void exception_handler virtual_exception(void);

int irq_install(int irq_num, irq_handler_t handler);
#endif