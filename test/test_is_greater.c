#include "s21_decimal_test.h"

START_TEST(test_s21_is_greater) {
  s21_decimal a = {{12345, 0, 0, 0}};         // +12345
  s21_decimal b = {{54322, 0, 0, 0}};         // +54322
  ck_assert_int_eq(s21_is_greater(b, a), 1);  // +54322 > +12345

  ck_assert_int_eq(s21_is_greater(a, b), 0);  // +12345 не больше +54322
}
END_TEST

Suite *suite_is_greater(void) {
  Suite *s = suite_create("suite_is_greater");
  TCase *tc = tcase_create("is_greater_tc");

  tcase_add_test(tc, test_s21_is_greater);

  suite_add_tcase(s, tc);

  return s;
}