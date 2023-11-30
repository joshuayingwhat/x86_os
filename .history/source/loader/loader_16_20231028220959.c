__asm__(".code16gcc"); // 设置成16位模式的代码
#include "loader.h"

static boot_info_t boot_info;

static void show_msg(const char *msg)
{
    char c;
    while ((c = *msg++) != '\0')
    {
        __asm__ __volatile__(
            "mov $0xe, %%ah\n\t"
            "mov %[ch], %%al\n\t"
            "int $0x10" ::[ch] "r"(c));
    }
}

/**
 * 检测内存容量
 */
static void detect_memory(void)
{
    uint32_t contID = 0;
    uint32_t signature, bytes;
    SMAP_entry_t smap_entry;

    show_msg("try do detect memory: ");
    boot_info.ram_region_count = 0;
    for (int i = 0; i < BOOT_RAW_REGION_MAX; i++)
    {
        SMAP_entry_t *entry = &smap_entry;

        __asm__ __volatile__("int $0x15"
                             : "=a"(signature), "=c"(bytes), "=b"(contID)
                             : "a"(0xE820), "b"(contID), "c"(24), "d"(0x534D4150), "D"(entry));

        if (signature != 0x534D4150)
        { // 如果内存检测结果为0x534D4150，表示失败
            show_msg("detect memory error!!!\n\r");
            return;
        }

        if (bytes > 20 && (entry->ACPI & 0x0001) == 0)
        {
            continue;
        }

        if (entry->Type == 1)
        { // 内存中有些地址需要被硬件占用("比如:显存")，因此如果type=1则说明当前地址可以被操作系统使用
            boot_info.ram_region_cfg[boot_info.ram_region_count].start = entry->BaseL;
            boot_info.ram_region_cfg[boot_info.ram_region_count].size = entry->LengthL;
            boot_info.ram_region_count++;
        }

        if (contID == 0)
        {
            break; // 整个读取结束
        }
    }
    show_msg("detect memory ok!!!\n\r");
}

uint16_t gdt_table[][4] = {
    {0, 0, 0, 0},
    {0xFFFF, 0x0000, 0x9a00, 0x00cf},
    {0xFFFF, 0x0000, 0x9200, 0x00cf},
};
static void enter_protected_mode(void)
{
    // 第一步:关中断
    cli();
    // 第二步:将a20地址线打开,内存可以访问4g的空间
    uint8_t v = inb(0x92);
    outb(0x92, v | 0x02);
    // 第三步:加载32位下的gdt表
    lgdt((uint32_t)gdt_table, sizeof(gdt_table));
    // 第四步:开启保护模式，设置cr0
    uint32_t cr0 = read_cr0();
    write_cr0();
}
void loader_entry(void)
{
    show_msg("------loading------\n\r");
    detect_memory();
    // 16位模式中处理完加载loader以及一些硬件检查后进入32位保护模式
    enter_protected_mode();
    for (;;)
    {
    }
}