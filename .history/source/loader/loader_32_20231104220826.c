#include "loader.h"

static void read_disk(int sector, int sector_count, uint8_t *buffer)
{
    outb(0x1F6, 0x40 | (slavebit << 4));
    outb(0x1F2,(u))
}

void load_kernel(void)
{
    for (;;)
    {
    }
}