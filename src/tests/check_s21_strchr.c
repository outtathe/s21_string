#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "../check_s21_string.h"
#include "../s21_string.h"

START_TEST(no_match_check_s21_strchr)
{
  ck_assert_ptr_null(s21_strchr("abcde", 'z'));
}
END_TEST

START_TEST(after_null_check_s21_strchr)
{
  ck_assert_ptr_null(s21_strchr("test\0string", 'g'));
}
END_TEST

START_TEST(additional_check_s21_strchr)
{
  char *test = (char *)malloc(12 * sizeof(char));
  strcpy(test, "test string");
  test = (void *)test;
  ck_assert_mem_eq(strchr(test, 't'), s21_strchr(test, 't'), 12);
  ck_assert_mem_eq(strchr(test+3, 's'), s21_strchr(test+3, 's'), 6);
  ck_assert_mem_eq(strchr(test, 'g'), s21_strchr(test, 'g'), 1);
  free(test);
}
END_TEST

Suite *s21_strchr_suite() {
  Suite *s = suite_create("s21_strchr");
  TCase *tc_corner = tcase_create("corner"), *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, no_match_check_s21_strchr);
  tcase_add_test(tc_corner, after_null_check_s21_strchr);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_strchr);
  suite_add_tcase(s, tc_additional);

  return s;
}