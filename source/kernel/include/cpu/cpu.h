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

#define GATE_TYPE_IDT (0xE << 8) // 中断32位门描述符
#define GATE_P_PRESENT (1 << 15) // 是否存在
#define GATE_DPL0 (0 << 13)      // 特权级0，最高特权级
#define GATE_DPL3 (3 << 13)      // 特权级3，最低权限

typedef struct _tss_t
{
    uint32_t pre_link;
    uint32_t esp0, ss0, esp1, ss1, esp2, ssp2;
    uint32_t cr3;
    uint32_t eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;
    uint32_t es, cs, ss, ds, fs, gs;
    uint32_t ldt;
    uint32_t iomap;
} tss_t;

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
void gate_desc_set(gate_desc_t *desc, uint16_t selector, uint32_t offset, uint16_t attr);
#endif