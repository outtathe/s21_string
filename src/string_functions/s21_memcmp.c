#include <stdbool.h>

#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n)
{
    int result = 0;
    bool found = false;
    for(s21_size_t i = 0; i < n && !found &&
        str1 + i != S21_NULL && str2 + i != S21_NULL;
        ++i)
            if(*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i))
            {
                found = true;
                if(str1 + n + 1 == S21_NULL || str2 + n + 1 == S21_NULL /*||
                   *(unsigned char *)(str1 + n) == '\0' || *(unsigned char *)(str2 + n) == '\0'*/)
                    result = (int)*(unsigned char *)(str1 + i) - (int)*(unsigned char *)(str2 + i);
                else if(*(unsigned char *)(str1 + i) < *(unsigned char *)(str2 + i))
                    --result;
                else
                    ++result;
            }
    return result;
}