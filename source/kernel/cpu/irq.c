#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "comm/cpu_instr.h"
#include "os_cfg.h"
#include "tools/log.h"

#define IDT_TABLE_NR 128
static gate_desc_t idt_table[IDT_TABLE_NR];
void exception_handler_unknow(void); // 中断异常入口地址

static void dump_core_regs(exception_frame_t *frame)
{
    log_prinf("IRQ: %d,errorCode: %d", frame->num, frame->error_code);
    log_prinf("CS:%d\nDS:%d\n ES:%d\nSS:%d\nFS:%d\nGS:%d\n",
              frame->cs, frame->ds, frame->es, frame->ds, frame->fs, frame->gs);

    log_prinf("EAX: 0x%x\n"
              "EBX: 0x%x\n"
              "ECX: 0x%x\n"
              "EDX: 0x%x\n"
              "EDI: 0x%x\n"
              "ESI: 0x%x\n"
              "EBP: 0x%x\n"
              "ESP: 0x%x\n",
              frame->eax,
              frame->ebx, frame->ecx, frame->edx, frame->edi, frame->esi, frame->ebp, frame->esp);

    // 发生异常的地址
    log_prinf("EIP: 0x%x\nEFLPAGS: 0x%x\n", frame->eip, frame->eflags);
}

static void do_default_handler(exception_frame_t *frame, const char *message)
{
    log_prinf("----------------------------");
    log_prinf("IRQ/Exception %s", message);
    dump_core_regs(frame);
    for (;;)
    {
        // 如果发生异常让cpu暂停运行
        hlt();
    }
}
// 中断异常处理函数
void do_handler_unknow(exception_frame_t *frame)
{
    do_default_handler(frame, "unknow exception!!!");
}

// 除0异常处理函数
void do_handler_divider(exception_frame_t *frame)
{
    do_default_handler(frame, "divider exception!!!");
}

void do_handler_Debug(exception_frame_t *frame)
{
    do_default_handler(frame, "Debug Exception");
}

void do_handler_NMI(exception_frame_t *frame)
{
    do_default_handler(frame, "NMI Interrupt.");
}

void do_handler_breakpoint(exception_frame_t *frame)
{
    do_default_handler(frame, "Breakpoint.");
}

void do_handler_overflow(exception_frame_t *frame)
{
    do_default_handler(frame, "Overflow.");
}

void do_handler_bound_range(exception_frame_t *frame)
{
    do_default_handler(frame, "BOUND Range Exceeded.");
}

void do_handler_invalid_opcode(exception_frame_t *frame)
{
    do_default_handler(frame, "Invalid Opcode.");
}

void do_handler_device_unavailable(exception_frame_t *frame)
{
    do_default_handler(frame, "Device Not Available.");
}

void do_handler_double_fault(exception_frame_t *frame)
{
    do_default_handler(frame, "Double Fault.");
}

void do_handler_invalid_tss(exception_frame_t *frame)
{
    do_default_handler(frame, "Invalid TSS");
}

void do_handler_segment_not_present(exception_frame_t *frame)
{
    do_default_handler(frame, "Segment Not Present.");
}

void do_handler_stack_segment_fault(exception_frame_t *frame)
{
    do_default_handler(frame, "Stack-Segment Fault.");
}

void do_handler_general_protection(exception_frame_t *frame)
{
    do_default_handler(frame, "General Protection.");
}

void do_handler_page_fault(exception_frame_t *frame)
{
    do_default_handler(frame, "Page Fault.");
}

void do_handler_fpu_error(exception_frame_t *frame)
{
    do_default_handler(frame, "X87 FPU Floating Point Error.");
}

void do_handler_alignment_check(exception_frame_t *frame)
{
    do_default_handler(frame, "Alignment Check.");
}

void do_handler_machine_check(exception_frame_t *frame)
{
    do_default_handler(frame, "Machine Check.");
}

void do_handler_smd_exception(exception_frame_t *frame)
{
    do_default_handler(frame, "SIMD Floating Point Exception.");
}

void do_handler_virtual_exception(exception_frame_t *frame)
{
    do_default_handler(frame, "Virtualization Exception.");
}

static void init_pic(void)
{
    // 对的一块8259芯片的初始化
    outb(PIC0_ICW1, PIC_ICW1_ALWAYS_1 | PIC_ICW1_ICW4);
    outb(PIC0_ICW2, IRQ_PIC_START);
    outb(PIC0_ICW3, 1 << 2);
    outb(PIC0_ICW4, PIC_ICW4_8086);

    // 对的二块8259芯片的初始化
    outb(PIC1_ICW1, PIC_ICW1_ALWAYS_1 | PIC_ICW1_ICW4);
    outb(PIC1_ICW2, IRQ_PIC_START + 8);
    outb(PIC1_ICW3, 2);
    outb(PIC1_ICW4, PIC_ICW4_8086);

    outb(PIC0_IMR, 0xFF & ~(1 << 2));
    outb(PIC1_IMR, 0xff);
}

// 初始化中断向量表
void irq_init(void)
{
    for (int i = 0; i < IDT_TABLE_NR; i++)
    {
        gate_desc_set(idt_table + i, KERNEL_SELECTOR_CS, (uint32_t)exception_handler_unknow, GATE_P_PRESENT | GATE_DPL0 | GATE_TYPE_IDT);
    }

    // 将异常处理配置到idt表中
    // 除0异常
    irq_install(IRQ0_DE, (irq_handler_t)exception_handler_divider);
    irq_install(IRQ1_DB, (irq_handler_t)exception_handler_Debug);
    irq_install(IRQ2_NMI, (irq_handler_t)exception_handler_NMI);
    irq_install(IRQ3_BP, (irq_handler_t)exception_handler_breakpoint);
    irq_install(IRQ4_OF, (irq_handler_t)exception_handler_overflow);
    irq_install(IRQ5_BR, (irq_handler_t)exception_handler_bound_range);
    irq_install(IRQ6_UD, (irq_handler_t)exception_handler_invalid_opcode);
    irq_install(IRQ7_NM, (irq_handler_t)exception_handler_device_unavailable);
    irq_install(IRQ8_DF, (irq_handler_t)exception_handler_double_fault);
    irq_install(IRQ10_TS, (irq_handler_t)exception_handler_invalid_tss);
    irq_install(IRQ11_NP, (irq_handler_t)exception_handler_segment_not_present);
    irq_install(IRQ12_SS, (irq_handler_t)exception_handler_stack_segment_fault);
    irq_install(IRQ13_GP, (irq_handler_t)exception_handler_general_protection);
    irq_install(IRQ14_PF, (irq_handler_t)exception_handler_page_fault);
    irq_install(IRQ16_MF, (irq_handler_t)exception_handler_fpu_error);
    irq_install(IRQ17_AC, (irq_handler_t)exception_handler_alignment_check);
    irq_install(IRQ18_MC, (irq_handler_t)exception_handler_machine_check);
    irq_install(IRQ19_XM, (irq_handler_t)exception_handler_smd_exception);
    irq_install(IRQ20_VE, (irq_handler_t)exception_handler_virtual_exception);

    lidt((uint32_t)idt_table, sizeof(idt_table));

    init_pic();
}

int irq_install(int irq_num, irq_handler_t handler)
{
    if (irq_num >= IDT_TABLE_NR)
    {
        return -1;
    }

    gate_desc_set(idt_table + irq_num, KERNEL_SELECTOR_CS, (uint32_t)handler, GATE_P_PRESENT | GATE_DPL0 | GATE_TYPE_IDT);
}

// 8259中断打开
void irq_enable(int irq_num)
{
    if (irq_num < IRQ_PIC_START)
    {
        return;
    }
    irq_num -= IRQ_PIC_START;
    if (irq_num < 8)
    {
        uint8_t mask = inb(PIC0_IMR) & ~(1 << irq_num);
        outb(PIC0_IMR, mask);
    }
    else
    {
        irq_num -= 8;
        uint8_t mask = inb(PIC1_IMR) & ~(1 << irq_num);
        outb(PIC1_IMR, mask);
    }
}

// 8259中断关闭
void irq_disable(int irq_num)
{
    if (irq_num < IRQ_PIC_START)
    {
        return;
    }
    irq_num -= IRQ_PIC_START;
    if (irq_num < 8)
    {
        uint8_t mask = inb(PIC0_IMR) | (1 << irq_num);
        outb(PIC0_IMR, mask);
    }
    else
    {
        irq_num -= 8;
        uint8_t mask = inb(PIC1_IMR) | (1 << irq_num);
        outb(PIC1_IMR, mask);
    }
}

// 全局中断关闭
void irq_disable_global(void)
{
    cli();
}

// 全局中断开启
void irq_enable_global(void)
{
    sti();
}

void pic_send_eoi(int irq_num)
{
    irq_num -= IRQ_PIC_START;
    if (irq_num >= 8)
    {
        outb(PIC1_OCW2, PIC_OCW2_EOI);
    }

    outb(PIC0_OCW2, PIC_OCW2_EOI);
}

// 进入临界区保护执行关中断
irq_state_t irq_enter_protection(void)
{
    irq_state_t state = read_eflags();
    irq_disable_global();
    return state;
}
// 退出临界区保护执行开中断
void irq_leave_protection(irq_state_t state)
{
    write_eflags(state);
}