#include "loader.h"

static void read_disk(uint32_t sector, uint32_t sector_count, uint8_t *buffer)
{
    outb(0x1F6, 0xE0);
    outb(0x1F2, (uint8_t)(sector_count >> 8));
    outb(0x1F3, (uint8_t)(sector >> 24));
    outb(0x1F4, 0);
    outb(0x1F5, 0);

    outb(0x1F2, (uint8_t)sector_count);
    outb(0x1F3, (uint8_t)sector);
    outb(0x1F4, (uint8_t)(sector >> 8));
    outb(0x1F5, (uint8_t)(sector >> 16));

    outb(0x1F7, 0x24);

    uint16_t *data_buf = (uint16_t *)buffer;

    while (sector_count--)
    {
        /* code */
        while ((inb(0x1F7) & 0x88) != 0x8)
        {
            /* code */
        }
        for (int i = 0; i < SECTOR_SIZE / 2; i++)
        {
            *data_buf++ = inw(0x1F0);
        }
    }
}

void load_kernel(void)
{
    // 将内核放在100个扇区的地方,将内存加载到1m地址处
    read_disk(100, 500, (uint8_t *)SYS_KERNEL_LOAD_ADDR);
    ((void (*)(void))SYS_KERNEL_LOAD_ADDR)();//跳转到loader中
    for (;;)
    {
    }
}