#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n)
{
    dest = s21_memcpy(dest, src, n);
    s21_size_t len = s21_strlen(dest);
    for(; len < n; ++len)
        dest[len] = '\0';
    return dest;
}