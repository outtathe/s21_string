#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "check_s21_string.h"

int main() {
  int number_failed = 0;
  SRunner *sr;

  // sr = srunner_create(s21_memchr_suite());
  sr = srunner_create(s21_strlen_suite());
  //srunner_add_suite(sr, s21_fabs_suite());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}