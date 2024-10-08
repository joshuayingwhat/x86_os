// 操作系统相关配置
#ifndef OS_CFG_H
#define OS_CFG_H

#define GDT_TABLE_SIZE 256 // gdt表的大小

#define KERNEL_SELECTOR_CS (1 * 8) // 设置代码段在gdt表中的第1个表项
#define KERNEL_SELECTOR_DS (2 * 8) // 设置数据段在gdt表中的第2个表项

#define KERNEL_STACK_SIZE (8 * 1024)

#define OS_TICKS_MS 10

#define IDLE_TASK_SIZE 1024

#define OS_VERSION "1.0.0"
#endif