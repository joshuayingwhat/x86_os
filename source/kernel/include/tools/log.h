#ifndef LOG_H
#define LOG_H

void init_log(); // 硬件初始化的输出文件

void log_prinf(const char *fmt, ...); // 和c语言一样的printf函数，这里和c语言区分log_printf

#endif