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

#define SET_G 
void cpu_init(void);
void segment_desc_set(int selector, uint32_t base, uint32_t limit, uint16_t attr);
#endif