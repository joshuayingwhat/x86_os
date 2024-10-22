#ifndef BOOT_INFO_H
#define BOOT_INFO_H

#include "types.h"

#define BOOT_RAW_REGION_MAX 10

typedef struct _boot_info_t
{
    struct
    {
        uint32_t start; // 起始地址
        uint32_t size;  // 大小
    } ram_region_cfg[BOOT_RAW_REGION_MAX];
    int ram_region_count;
} boot_info_t;

#define SECTOR_SIZE 512
#define SYS_KERNEL_LOAD_ADDR (1024 * 1024)
#endif