#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n)
{
    for(s21_size_t i = 0; i < n && str + i != S21_NULL; ++i)
        *(unsigned char *)(str + i) = (unsigned char)c;
    return str;
}