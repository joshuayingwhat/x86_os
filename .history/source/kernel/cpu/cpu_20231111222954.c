#include "cpu/cpu.h"

static segment_desc_t gdt_table[GDT_TABLE_SIZE];

void segment_desc_set(int selector,uint32_t base,uin)