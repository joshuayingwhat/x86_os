#include "init.h"
#include "comm/boot_info.h"
#include "cpu/cpu.h"

/**
 * 内核入口
 */
void kernel_init(boot_info_t *boot_info)
{
    int locar_var;
    static int static_local_var = 0x33;
    static int static_local_var_zero;

    for (;;)
    {
    }
}