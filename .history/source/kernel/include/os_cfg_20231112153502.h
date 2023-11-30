// 操作系统相关配置
#ifndef OS_CFG_H
#define OS_CFG_H

#define GDT_TABLE_SIZE 256 // gdt表的大小

#define KERNEL_SELECTOR_CS (1 * 8) // 设置代码段在gdt表中的第1个表项
#define KERNEL_SELECTOR_DS (2 * 8) //设置代码段在gdt表中的第1个表项
#endif