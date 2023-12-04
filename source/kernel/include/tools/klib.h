#ifndef KLIB_H
#define KLIB_H
#include "comm/types.h"

void kernel_strcpy(char *dest, char *src); // 字符串的复制

void kernel_strncpy(const char *dest, const char *src, int size); // 字符串最多可以复制多少字符

int kernel_strncmp(const char *s1, const char *s2, int size); // 字符串比较

int kernel_strlen(const char *str); // 字符串长度

void kernel_memcpy(void *dest, void *src, int size); // 内存复制

void kernel_memset(void *dest, uint8_t v, int size);

int kernel_memcmp(void *d1, void *d2, int size);
#endif