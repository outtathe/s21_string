#include <stdbool.h>

#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n)
{
    void *result = S21_NULL;
    bool found = false;
    for(s21_size_t i = 0; i < n && *(unsigned char *)(str + i) != '\0' && !found; ++i)
        if(*(unsigned char *)(str + i) == (unsigned char)c)
        {
            result = (void *)(str + i);
            found = true;
        }
    return result;
}