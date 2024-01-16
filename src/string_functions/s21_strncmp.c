#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n)
{
    s21_size_t len1 = s21_strlen(str1), len2 = s21_strlen(str2);
    n = n < len1 ? n : len1;
    n = n < len2 ? n : len2;
    return s21_memcmp(str1, str2, n);
}