#include "loader.h"

static void read_disk(uint32_t sector, uint32_t sector_count, uint8_t *buffer)
{
    outb(0x1F6, 0xE0);
    outb(0x1F2, (uint8_t)sector_count >> 8);
    outb(0x1F3, (uint8_t));
}

void load_kernel(void)
{
    for (;;)
    {
    }
}