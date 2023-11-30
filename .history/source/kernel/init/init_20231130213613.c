#include "init.h"
#include "comm/boot_info.h"
#include "cpu/cpu.h"
#include "dev/timer.h"

/**
 * 内核入口
 */
void kernel_init(boot_info_t *boot_info)
{
    cpu_init();
    irq_init();
    //初始化定时器
    init
}

void init_main()
{
    int a = 3 / 0;
    for (;;)
    {
    }
}