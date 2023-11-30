// cpu相关的一些配置结构
#ifndef CPU_H
#define CPU_H

#include "comm/types.h"

#pragma pack(1)
// 定义gdt表的结构
typedef struct _segment_desc_t
{
    uint16_t limit15_0;
    uint16_t base15_0;
    uint8_t base23_16;
    uint16_t attr;
    uint8_t base31_24;
} segment_desc_t;

// 定义ldt表的结构
typedef struct _gate_desc_t
{
    uint16_t offset15_0;
    uint16_t selector;
    uint16_t attr;
    uint16_t offset31_16;
} gate_desc_t;

#pragma pack()

#define SEG_G (1 << 15) // gdt的g标识位
#define SEG_D (1 << 14)
#define SEG_PRESENT (1 << 7)

#define SEG_DPL0 (0 << 5) // 内核的特权级为0
#define SEG_DPL3 (3 << 5) // 普通程序的特权级设置为3

#define SEG_S_SYSTEM (0 << 4)
#define SEG_S_NORMAL (1 << 4)

#define SEG_TYPE_CODE (1 << 3) // gdt表中代码段的类型
#define SEG_TYPE_DATA (0 << 3) // gdt表中数据段的类型

#define SEG_TYPE_RW (1 << 1) // 数据段是否可以读写

void cpu_init(void);
void segment_desc_set(int selector, uint32_t base, uint32_t limit, uint16_t attr);
void gate_desc_set(gate_desc_set *desc, uint16_t selector,uint32_t ,uint16_t attr);
#endif