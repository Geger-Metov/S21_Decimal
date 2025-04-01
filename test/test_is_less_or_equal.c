#include "s21_decimal_test.h"

START_TEST(test_s21_is_less_or_equal) {
  s21_decimal a = {{12345, 0, 0, 0}};               // +12345
  s21_decimal b = {{54322, 0, 0, 0}};               // +54322
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);  // +12345 <= +54322

  ck_assert_int_eq(s21_is_less_or_equal(b, a), 0);  // +54322 не <= +12345

  ck_assert_int_eq(s21_is_less_or_equal(a, a), 1);  // +12345 <= +12345 (равно)
}
END_TEST

Suite *suite_is_less_or_equal(void) {
  Suite *s = suite_create("suite_is_less_or_equal");
  TCase *tc = tcase_create("is_less_or_equal_tc");

  tcase_add_test(tc, test_s21_is_less_or_equal);

  suite_add_tcase(s, tc);

  return s;
}