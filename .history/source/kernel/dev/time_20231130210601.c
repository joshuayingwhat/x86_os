#include "time.h"
#include "comm/types.h"

static uint32_t sys_tick; // 每一次中断加一

static init

void time_init(void)
{
    sys_tick = 0;
    init_pit();
}