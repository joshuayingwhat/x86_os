#include "time.h"
#include "comm/types.h"
#include "comm/cpu_instr.h"
#include "include/"

static uint32_t sys_tick; // 每一次中断加一

static void init_pic(void)
{
    uint32_t reload_count = PIT_OSC_FREQ / (1000.0 * OS_TICKS_MS);
    outb(PIT_COMMAND_MODE_PORT, PIT_CHANNEL | PIT_LOAD_LOHI | PIT_MODE3);
    outb(PIT_CHANNEL0_DATA_PORT, reload_count & 0xFF);
    outb(PIT_CHANNEL0_DATA_PORT, (reload_count >> 8) & 0xFF);
}

void time_init(void)
{
    sys_tick = 0;
    init_pit();
}