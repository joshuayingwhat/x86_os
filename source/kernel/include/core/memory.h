#ifndef MEMORY_H
#define MEMORY_H

#include "comm/types.h"
#include "tools/bitmap.h"
#include "ipc/mutex.h"
#include "comm/boot_info.h"
typedef struct _addr_alloc_t
{
    mutex_t mutex;      // 互斥信号量，这个结构可能被多个进程使用
    bitmap_t bitmap;    // 标记当前内存是否分配
    uint32_t start;     // 分配的起始地址
    uint32_t size;      // 总的分配的大小
    uint32_t page_size; // 分配的块的大小
} addr_alloc_t;         // 用于内存的分配和释放，对地址进行分配

void memory_init(boot_info_t *boot_info); // 对计算机整个内存初始化
#endif