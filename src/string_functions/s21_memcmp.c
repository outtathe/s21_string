#include <stdbool.h>

#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n)
{
    int result = 0;
    bool found = false;
    for(s21_size_t i = 0; i < n && !found &&
        *(unsigned char *)(str1 + i) != '\0' && *(unsigned char *)(str2 + i) != '\0';
        ++i)
            if(*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i))
            {
                found = true;
                if(*(unsigned char *)(str1 + i) > *(unsigned char *)(str2 + i))
                    ++result;
                else
                    --result;
            }
    return result;
}