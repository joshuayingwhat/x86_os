#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "comm/cpu_instr.h"
#include "os_cfg.h"

#define IDT_TABLE_NR 128
static gate_desc_t idt_table[IDT_TABLE_NR];
void exception_handle_unknow(void); // 中断异常入口地址

static do_default_handle(exception_frame_t *frame, const *message)
{
    for (;;)
    {
    }
}
// 中断异常处理函数
void do_handler_unknow(exception_frame_t *frame)
{
    do_default_handle(frame, "unknow exception!!!");
}

// 除0异常处理函数
void do_handler_divider(exception_frame_t *frame)
{
    do_default_handle(frame, "divider exception!!!");
}
// 初始化中断向量表
void irq_init(void)
{
    for (int i = 0; i < IDT_TABLE_NR; i++)
    {
        gate_desc_set(idt_table + i, KERNEL_SELECTOR_CS, (uint32_t)exception_handle_unknow, GATE_P_PRESENT | GATE_DPL0 | GATE_TYPE_IDT);
    }

    
    lidt((uint32_t)idt_table, sizeof(idt_table));
}

int irq_install(int irq_num, irq_handler_t handler)
{
}