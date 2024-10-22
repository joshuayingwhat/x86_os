#include "core/memory.h"

static void addr_alloc_init(addr_alloc_t *alloc, uint8_t *bits,
                            uint32_t start, uint32_t size, uint32_t page_size)
{
    mutex_init(&alloc->mutex);
    alloc->start = start;
    alloc->size = size;
    alloc->page_size = page_size;
    bitmap_init(&alloc->bitmap, bits, alloc->size / alloc->page_size, 0);
}

static uint32_t addr_alloc_page(addr_alloc_t *alloc, int page_count)
{
    uint32_t addr = 0;
    mutex_lock(&alloc->mutex);
    int page_index = bitmap_alloc_nbits(&alloc->bitmap, 0, page_count);
    if (page_index >= 0)
    {
        addr = alloc->start + page_index * alloc->page_size;
    }
    mutex_unlock(&alloc->mutex);
    return addr;
}

static void addr_free_page(addr_alloc_t *alloc, uint32_t addr, int page_count)
{
    mutex_lock(&alloc->mutex);
    uint32_t pg_index = (addr - alloc->start) / alloc->page_size;
    bitmap_set_bit(&alloc->bitmap, pg_index, page_count, 0);
    mutex_unlock(&alloc->mutex);
}
// 对计算机整个内存初始化
void memory_init(boot_info_t *boot_info)
{
    addr_alloc_t add_alloc;
    uint8_t bits[8];
    addr_alloc_init(&add_alloc, bits, 0x1000, 64 * 4096, 4096);
    for (int i = 0; i < 32; i++)
    {
        uint32_t addr = addr_alloc_page(&add_alloc, 2);
    }

    uint32_t addr = 0x1000;
    for (int i = 0; i < 32; i++)
    {
        addr_free_page(&add_alloc, addr, 2);
        addr += 8192;
    }
}