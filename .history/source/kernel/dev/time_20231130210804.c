#include "time.h"
#include "comm/types.h"
#include "comm/cpu_instr.h"

static uint32_t sys_tick; // 每一次中断加一

static void init_pic(void)
{
    outb(PIT_COMMAND_MODE_PORT,);
}

void time_init(void)
{
    sys_tick = 0;
    init_pit();
}