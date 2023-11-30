#ifndef TIME_H
#define TIME_H

#define PIC_OSC_FREQ 1193182
#define PIC_

void time_init(void);              // 定时器初始化函数
void exception_handler_time(void); // 中断处理函数
#endif