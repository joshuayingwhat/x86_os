#include "tools/klib.h"
#include "comm/types.h"
// 字符串的复制
void kernel_strcpy(char *dest,char *src)
{
    if (!dest || !src)
    {
        return;
    }
    while (*dest && *src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// 字符串最多可以复制多少字符
void kernel_strncpy(const char *dest, const char *src, int size)
{
    if (!dest || !src || !size)
    {
        return;
    }
    char *d = dest;
    const char *s = src;
    while ((size-- > 0) && (*s))
    {
        *d++ = *s++;
    }
    if (size == 0)
    {
        *(d - 1) = '\0';
    }
    else
    {
        *d = '\0';
    }
}

// 字符串比较
int kernel_strncmp(const char *s1, const char *s2, int size)
{
    if (!s1 || !s2 || !size)
    {
        return -1;
    }
    while (*s1 && *s2 && (*s1 == *s2) && size)
    {
        s1++;
        s2++;
    }

    return !((*s1 == '\0') || (*s2 == '\0') || (*s1 == *s2));
}

// 字符串长度
int kernel_strlen(const char *str)
{
    if (!str)
    {
        return 0;
    }
    const char *c = str;
    int len = 0;
    while (*c++)
    {
        len++;
    }
    return len;
}

// 内存复制
void kernel_memcpy(void *dest, void *src, int size)
{
    if (!dest || !src || !size)
    {
        return;
    }

    uint8_t *s = (uint8_t *)src;
    uint8_t *d = (uint8_t *)dest;

    while (size--)
    {
        *d++ = *s++;
    }
}

// 将一块内存的值设置为指定的字节
void kernel_memset(void *dest, uint8_t v, int size)
{
    if (!dest || !size)
    {
        return;
    }
    uint8_t *d = (uint8_t *)dest;
    while (size--)
    {
        *d++ = v;
    }
}

int kernel_memcmp(void *d1, void *d2, int size)
{
    if (!d1 || !d2)
    {
        return 1;
    }

    uint8_t *p_d1 = (uint8_t *)d1;
    uint8_t *p_d2 = (uint8_t *)d2;
    while (size--)
    {
        if (*p_d1++ != *p_d2++)
        {
            return 1;
        }
    }
    return 0;
}