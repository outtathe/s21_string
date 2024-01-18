#include "../check_s21_string.h"
#include "../s21_string.h"

#include <stdio.h>

START_TEST(full_len_check_s21_memset)
{
    void *dest1 = malloc(4 * sizeof(char)), *dest2 = malloc(4 *sizeof(char));
    ck_assert_mem_eq(memset(dest1, 't', 4), s21_memset(dest2, 't', 4), 4);
    free(dest1);
    free(dest2);
}
END_TEST

START_TEST(additional_check_s21_memset)
{
  void *dest1 = malloc(12 * sizeof(char)), *dest2 = malloc(12 *sizeof(char));
  ck_assert_mem_eq(memset(dest1, 'l', 2), s21_memset(dest2, 'l', 2), 2);
  ck_assert_mem_eq(memset(dest1, 'r', 5), s21_memset(dest2, 'r', 5), 5);
  ck_assert_mem_ne(memset(dest1, '1', 11), s21_memset(dest2, '1', 10), 11);
  ck_assert_mem_ne(memset(dest1, '1', 11), s21_memset(dest2, '1', 11), 12);
  free(dest1);
  free(dest2);
}
END_TEST

Suite *s21_memset_suite() {
  Suite *s = suite_create("s21_memset");
  TCase *tc_corner = tcase_create("corner"), *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, full_len_check_s21_memset);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_memset);
  suite_add_tcase(s, tc_additional);

  return s;
}