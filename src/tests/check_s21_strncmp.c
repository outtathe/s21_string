#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "../check_s21_string.h"
#include "../s21_string.h"

START_TEST(left_check_s21_strncmp)
{
  ck_assert_int_eq(strncmp("test", "Test", 4), s21_strncmp("test", "Test", 4));
}
END_TEST

START_TEST(right_check_s21_strncmp)
{
  ck_assert_int_eq(strncmp("Test", "test", 4), s21_strncmp("Test", "test", 4));
}
END_TEST

START_TEST(equal_check_s21_strncmp)
{
  ck_assert_int_eq(strncmp("test", "test", 4), s21_strncmp("test", "test", 4));
}
END_TEST

START_TEST(after_null_check_s21_strncmp)
{
  ck_assert_int_eq(strncmp("test\0lol", "test\0kek", 6), s21_strncmp("test\0lol", "test\0kek", 6));
}
END_TEST

START_TEST(additional_check_s21_strncmp)
{
  ck_assert_int_eq(strncmp("aboba", "AbObA", 5), s21_strncmp("aboba", "AbObA", 5));
  ck_assert_int_eq(strncmp("1lol", "2lol", 4), s21_strncmp("1lol", "2lol", 4));
  ck_assert_int_eq(strncmp("check", "check kek", 5), s21_strncmp("check", "check kek", 5));
}
END_TEST

Suite *s21_strncmp_suite() {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc_corner = tcase_create("corner"), *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, left_check_s21_strncmp);
  tcase_add_test(tc_corner, right_check_s21_strncmp);
  tcase_add_test(tc_corner, equal_check_s21_strncmp);
  tcase_add_test(tc_corner, after_null_check_s21_strncmp);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_strncmp);
  suite_add_tcase(s, tc_additional);

  return s;
}