#include "time.h"
#include "comm/types.h"
#include "comm/cpu_instr.h"
#include "include/os_cfg.h"
#include "include/cpu/irq.h"

static uint32_t sys_tick; // 每一次中断加一

static void init_pic(void)
{
    uint32_t reload_count = PIT_OSC_FREQ * OS_TICKS_MS / 1000;
    outb(PIT_COMMAND_MODE_PORT, PIT_CHANNEL | PIT_LOAD_LOHI | PIT_MODE3);
    outb(PIT_CHANNEL0_DATA_PORT, reload_count & 0xFF);
    outb(PIT_CHANNEL0_DATA_PORT, (reload_count >> 8) & 0xFF);

    irq_install(IRQ0_TIMER, (irq_handler_t)exception_handler_time);//添加到中断函数中
    irq_enable(IRQ0_TIMER);//打开定时zhong du
}

void time_init(void)
{
    sys_tick = 0;
    init_pit();
}