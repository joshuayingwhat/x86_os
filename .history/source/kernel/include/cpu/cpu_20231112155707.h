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

#pragma pack()

#define SEG_G (1 << 15); // gdt的g标识位
#define SEG_D (1 << 14);
#define SEG_PRESENT (1 << 7);

#define SEG_DPL0 (0 << 5); // 内核的特权级为0
#define SEG_DPL3 (3 << 5); // 普通程序的特权级设置为3

#define SEG_S_SYSTEM (0 << 4);
#define SEG_S_NORMAL (1 << 4);

#define SEG_TYPE_CODE (1 << 3); // gdt表中代码类型
#define SEG_TYPE_CODE (1 << 3); // 代码类型

void cpu_init(void);
void segment_desc_set(int selector, uint32_t base, uint32_t limit, uint16_t attr);
#endif