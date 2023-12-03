#include "cpu/irq.h"
#include "cpu/cpu.h"

#define IDT_TABLE_NR 128
static gate_desc_t idt_table[IDT_TABLE_NR];

// 初始化中断向量表
void irq_init(void)
{
    for (int i = 0; i < IDT_TABLE_NR; i++)
    {
        gate_desc_set(idt_table + i, 0, 0, 0);
    }
}