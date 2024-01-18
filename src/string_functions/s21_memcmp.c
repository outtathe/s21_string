#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n)
{
    int result = 0;
    bool found = false;
    s21_size_t len1 = s21_strlen(str1), len2 = s21_strlen(str2);
    for(s21_size_t i = 0; i < n && !found &&
        str1 + i != S21_NULL && str2 + i != S21_NULL;
        ++i)
            if(*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i))
            {
                found = true;
                if(len1 + 1 <= n || len2 + 1 <= n)
                    result = (int)*(unsigned char *)(str1 + i) - (int)*(unsigned char *)(str2 + i);
                else if(*(unsigned char *)(str1 + i) < *(unsigned char *)(str2 + i))
                    --result;
                else
                    ++result;
            }
    return result;
}