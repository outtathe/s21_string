#include "../check_s21_string.h"
#include "../s21_string.h"


Suite *s21_strlen_suite() {
  Suite *s = suite_create("s21_strlen");
  TCase *tc_corner = tcase_create("corner");//, *tc_additional = tcase_create("additional");

//  tcase_add_test(tc_corner, nullptr_check_s21_strlen);
//   tcase_add_test(tc_corner, beyond_end_check_s21_memchr);
  suite_add_tcase(s, tc_corner);

//   tcase_add_test(tc_additional, additional_check_s21_memchr);
//   suite_add_tcase(s, tc_additional);

  return s;
}