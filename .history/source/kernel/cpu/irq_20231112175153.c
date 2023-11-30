#include "cpu/irq.h"
#include "cpu/cpu.h"

#define IDT_TABLE_ 128
static gate_desc_t idt_table[IDT_TABLE];

// 初始化中断向量表
void irq_init(void)
{
}