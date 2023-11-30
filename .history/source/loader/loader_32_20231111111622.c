#include "loader.h"
#include "comm/elf.h"

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

static uint32_t reload_elf_file(uint8_t *file_buffer)
{
    Elf32_Ehdr *elf_hdr = (Elf32_Ehdr *)file_buffer;
    // 检查该文件是否是elf文件
    if ((elf_hdr->e_ident[0] != 0x7F) ||
        (elf_hdr->e_ident[1] != 'E') ||
        (elf_hdr->e_ident[2] != 'L') ||
        (elf_hdr->e_ident[3] != 'F'))
    {
        return 0; // 直接退出
    }

    for (int i = 0; i < elf_hdr->e_phnum; i++)
    {
        Elf32_Phdr *phdr = (Elf32_Phdr *)(file_buffer + elf_hdr->e_phoff) + i;
        if (phdr->p_type != PT_LOAD)
        {
            continue;
        }
        uint8_t *src = file_buffer+phdr->p
    }
}

void load_kernel(void)
{
    // 将内核放在100个扇区的地方,将内存加载到1m地址处
    read_disk(100, 500, (uint8_t *)SYS_KERNEL_LOAD_ADDR);

    reload_elf_file((uint8_t *)SYS_KERNEL_LOAD_ADDR); // 解析elf文件进入内核

    ((void (*)(boot_info_t *))SYS_KERNEL_LOAD_ADDR)(&boot_info); // 跳转到内核中SYS_KERNEL_LOAD_ADDR对应的地址就是init/start.S中的_start
    for (;;)
    {
    }
}