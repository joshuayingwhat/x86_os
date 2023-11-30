#include "cpu/irq.h"
#include "cpu/cpu.h"

#define IDT_TABLE 128
static gate_desc_t idt_table[255];

// 初始化中断向量表
void irq_init(void)
{
}