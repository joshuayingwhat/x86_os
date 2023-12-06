#include "tools/klib.h"
#include "comm/types.h"
// 字符串的复制
void kernel_strcpy(char *dest, char *src)
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

void kernel_sprintf(char *buffer, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    kernel_vsprintf(buffer, fmt, args);
    va_end(args);
}

void kernel_itoa(char *buf, int num, int base)
{
    static const char *num2ch = {"FEDCBA9876543210123456789ABCDEF"};
    char *p = buf;
    int old_num = num;
    if ((base != 2) && (base != 8) && (base != 10) && (base != 16))
    {
        *p = '\0';
        return;
    }
    if ((num < 0) && (base == 10))
    {
        *p++ = '-';
    }
    do
    {
        char ch = num2ch[num % base + 15];
        *p++ = ch;
        num /= base;
    } while (num);
    *p-- = '\0';
    char *start = (old_num > 0) ? buf : buf + 1;
    while (start < p)
    {
        char ch = *start;
        *start = *p;
        *p = ch;

        p--;
        start++;
    }
}

void kernel_vsprintf(char *buffer, const char *fmt, va_list args)
{
    enum
    {
        NORMAL,
        READ_FMT
    } state = NORMAL;
    char ch;
    char *curr = buffer;
    while ((ch = *fmt++))
    {
        switch (state)
        {
        // 普通字符
        case NORMAL:
            if (ch == '%')
            {
                state = READ_FMT;
            }
            else
            {
                *curr++ = ch;
            }
            break;
        // 格式化控制字符，只支持部分
        case READ_FMT:
            if (ch == 'd')
            {
                int num = va_arg(args, int);
                kernel_itoa(curr, num, 10);
                curr += kernel_strlen(curr);
            }
            else if (ch == 'x')
            {
                int num = va_arg(args, int);
                kernel_itoa(curr, num, 16);
                curr += kernel_strlen(curr);
            }
            else if (ch == 'c')
            {
                char c = va_arg(args, int);
                *curr = c;
            }
            else if (ch == 's')
            {
                const char *str = va_arg(args, char *);
                int len = kernel_strlen(str);
                while (len--)
                {
                    *curr++ = *str++;
                }
            }
            state = NORMAL;
            break;
        }
    }
}