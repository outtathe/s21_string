#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n)
{
    int result = 0;
    bool found = false;
    for(s21_size_t i = 0; i < n && !found && *(unsigned char *)(str1 + i) != '\0' && *(unsigned char *)(str2 + i) != '\0'; ++i)
        if(*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i))
        {
            found = true;
            result = (int)*(unsigned char *)(str1 + i) - (int)*(unsigned char *)(str2 + i);
        }
    return result;
}