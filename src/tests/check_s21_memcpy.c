#include "../check_s21_string.h"
#include "../s21_string.h"

START_TEST(additional_check_s21_memcpy)
{
  void *dest1 = malloc(12 * sizeof(char)), *dest2 = malloc(12 *sizeof(char));
  ck_assert_mem_eq(memcpy(dest1, "hello", 5), s21_memcpy(dest2, "hello", 5), 5);
  ck_assert_mem_eq(memcpy(dest1, "hello", 4), s21_memcpy(dest2, "hello", 4), 4);
  ck_assert_mem_ne(memcpy(dest1, "hellw", 5), s21_memcpy(dest2, "helld", 5), 5);
  free(dest1);
  free(dest2);
}
END_TEST

Suite *s21_memcpy_suite() {
  Suite *s = suite_create("s21_memcpy");
  TCase /**tc_corner = tcase_create("corner"),*/ *tc_additional = tcase_create("additional");

  //tcase_add_test(tc_corner, beyond_end_check_s21_memcpy);
  //tcase_add_test(tc_corner, no_match_check_s21_memcpy);
  //suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_memcpy);
  suite_add_tcase(s, tc_additional);

  return s;
}