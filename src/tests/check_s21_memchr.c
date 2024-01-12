#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "../check_s21_string.h"
#include "../s21_string.h"

START_TEST(beyond_end_check_s21_memchr)
{
  ck_assert_ptr_null(s21_memchr("abcde", 'e', 2));
}
END_TEST

START_TEST(no_match_check_s21_memchr)
{
  ck_assert_ptr_null(s21_memchr("abcde", 'z', 5));
}
END_TEST

START_TEST(additional_check_s21_memchr)
{
  char *test = (char *)malloc(12 * sizeof(char));
  strcpy(test, "test string");
  test = (void *)test;
  ck_assert_mem_eq(memchr(test, 't', 5), s21_memchr(test, 't', 5), 12);
  ck_assert_mem_eq(memchr(test+3, 's', 4), s21_memchr(test+3, 's', 4), 6);
  ck_assert_mem_eq(memchr(test, 'g', 99), s21_memchr(test, 'g', 99), 1);
  free(test);
}
END_TEST

Suite *s21_memchr_suite() {
  Suite *s = suite_create("s21_memchr");
  TCase *tc_corner = tcase_create("corner"), *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, beyond_end_check_s21_memchr);
  tcase_add_test(tc_corner, no_match_check_s21_memchr);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_memchr);
  suite_add_tcase(s, tc_additional);

  return s;
}