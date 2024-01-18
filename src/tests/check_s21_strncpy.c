#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "../check_s21_string.h"
#include "../s21_string.h"

START_TEST(additional_check_s21_strncpy)
{
  void *dest1 = malloc(12 * sizeof(char)), *dest2 = malloc(12 *sizeof(char));
  ck_assert_mem_eq(strncpy(dest1, "hello", 12), s21_strncpy(dest2, "hello", 12), 12);
  ck_assert_mem_eq(strncpy(dest1, "hello", 6), s21_strncpy(dest2, "hello", 6), 6);
  ck_assert_mem_ne(strncpy(dest1, "hellw", 6), s21_strncpy(dest2, "helld", 6), 6);
  free(dest1);
  free(dest2);
}
END_TEST

Suite *s21_strncpy_suite() {
  Suite *s = suite_create("s21_strncpy");
  TCase /**tc_corner = tcase_create("corner"),*/ *tc_additional = tcase_create("additional");

  //tcase_add_test(tc_corner, beyond_end_check_s21_strncpy);
  //tcase_add_test(tc_corner, no_match_check_s21_strncpy);
  //suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_strncpy);
  suite_add_tcase(s, tc_additional);

  return s;
}