#ifndef KLIB_H
#define KLIB_H

#include "comm/types.h"
#include "stdarg.h"

void kernel_strcpy(char *dest, char *src); // 字符串的复制

void kernel_strncpy(const char *dest, const char *src, int size); // 字符串最多可以复制多少字符

int kernel_strncmp(const char *s1, const char *s2, int size); // 字符串比较

int kernel_strlen(const char *str); // 字符串长度

void kernel_memcpy(void *dest, void *src, int size); // 内存复制

void kernel_memset(void *dest, uint8_t v, int size);

int kernel_memcmp(void *d1, void *d2, int size);

void kernel_sprintf(char *buffer, const char *fmt, ...);

void kernel_vsprintf(char *buffer, const char *fmt, va_list args); // 格式化字符串

#ifndef RELEASE
#define ASSERT(expr) \
    if (!(expr))     \
    pannic(__FILE__, __LINE__, __func__, #expr) // 如果expr不成立错误则执行

void pannic(const char *file, int line, const char *func, const char *cond);
#else
#define ASSERT(expr) ((void)0)
#endif

#endif