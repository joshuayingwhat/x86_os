#include "loader.h"

static void read_disk(int sector, int sector_count, uint8_t *buffer)
{
    outb(0x1F6, 0xE0);
    outb(0x1F2, (uint8_t)sector_count << 8);
}

void load_kernel(void)
{
    for (;;)
    {
    }
}