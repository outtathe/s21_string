#ifndef CHECK_S21_STRING_H
#define CHECK_S21_STRING_H

#include <check.h>
#include <string.h>
#include <stdlib.h>

Suite *s21_memchr_suite();
Suite *s21_memcmp_suite();
Suite *s21_memcpy_suite();
Suite *s21_memset_suite();
Suite *s21_strlen_suite();
Suite *s21_strchr_suite();
Suite *s21_strncmp_suite();
Suite *s21_strncpy_suite();

#endif