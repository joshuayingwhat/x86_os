#include "stdarg.h"
#include "tools/log.h"
#include "tools/klib.h"
#include "comm/cpu_instr.h"
#include "cpu/irq.h"

#define COM1_PORT 0X3F8
void init_log()
{
    // 对硬件初始化
    outb(COM1_PORT + 1, 0x00);
    outb(COM1_PORT + 3, 0x80);
    outb(COM1_PORT + 0, 0x3);
    outb(COM1_PORT + 1, 0x00);
    outb(COM1_PORT + 3, 0x03);
    outb(COM1_PORT + 2, 0x07);
    outb(COM1_PORT + 4, 0x0F);
}

void log_prinf(const char *fmt, ...)
{
    char str_buf[128];
    va_list args;
    kernel_memset(str_buf, '\0', sizeof(str_buf));
    va_start(args, fmt);

    kernel_vsprintf(str_buf, fmt, args);
    va_end(args);

    irq_state_t state = irq_enter_protection();
    const char *p = str_buf;
    while (*p != '\0')
    {
        while ((inb(COM1_PORT + 5) & (1 << 6)) == 0)
            ;
        outb(COM1_PORT, *p++);
    }

    // 输出完成后换行，回车
    outb(COM1_PORT, '\r');
    outb(COM1_PORT, '\n');
    irq_leave_protection(state);
}
