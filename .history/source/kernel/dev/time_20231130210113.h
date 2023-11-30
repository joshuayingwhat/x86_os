#ifndef TIME_H
#define TIME_H

#define PIC_OSC_FREQ 1193182
#define PIC_COMMAND_MODE_PORT 0x43
#define 

void time_init(void);              // 定时器初始化函数
void exception_handler_time(void); // 中断处理函数
#endif