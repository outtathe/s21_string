#include "../check_s21_string.h"
#include "../s21_string.h"

START_TEST(left_check_s21_memcmp)
{
  ck_assert_int_eq(memcmp("test", "Test", 4), s21_memcmp("test", "Test", 4));
}
END_TEST

START_TEST(right_check_s21_memcmp)
{
  ck_assert_int_eq(memcmp("Test", "test", 4), s21_memcmp("Test", "test", 4));
}
END_TEST

START_TEST(equal_check_s21_memcmp)
{
  ck_assert_int_eq(memcmp("test", "test", 4), s21_memcmp("test", "test", 4));
}
END_TEST

START_TEST(beyond_end_check_s21_memcmp)
{
  ck_assert_int_eq(memcmp("test", "testT", 6), s21_memcmp("test", "testT", 6));
}
END_TEST

START_TEST(additional_check_s21_memcmp)
{
  ck_assert_int_eq(memcmp("aboba", "AbObA", 5), s21_memcmp("aboba", "AbObA", 5));
  ck_assert_int_eq(memcmp("1lol", "2lol", 4), s21_memcmp("1lol", "2lol", 4));
  ck_assert_int_eq(memcmp("check", "check kek", 5), s21_memcmp("check", "check kek", 5));
}
END_TEST

Suite *s21_memcmp_suite() {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc_corner = tcase_create("corner"), *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, left_check_s21_memcmp);
  tcase_add_test(tc_corner, right_check_s21_memcmp);
  tcase_add_test(tc_corner, equal_check_s21_memcmp);
  tcase_add_test(tc_corner, beyond_end_check_s21_memcmp);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_memcmp);
  suite_add_tcase(s, tc_additional);

  return s;
}