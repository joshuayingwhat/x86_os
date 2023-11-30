#include "loader.h"

static void read_disk(int sector, int sector_count, uint8_t *buffer)
{
    outb(0x1);
}

void load_kernel(void)
{
    for (;;)
    {
    }
}