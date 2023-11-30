#ifndef TIME_H
#define TIME_H

#define PIT_OSC_FREQ 1193182
#define PIT_COMMAND_MODE_PORT 0x43
#define PIT_CHANNEL0_DATA_PORT 0x40
#define PIT

void time_init(void);              // 定时器初始化函数
void exception_handler_time(void); // 中断处理函数
#endif