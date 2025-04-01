#include "s21_decimal_test.h"

START_TEST(test_s21_is_less) {
  s21_decimal a = {{12345, 0, 0, 0}};      // 12345
  s21_decimal b = {{54322, 0, 0, 0}};      // 54322
  ck_assert_int_eq(s21_is_less(a, b), 1);  // Ожидаем TRUE

  ck_assert_int_eq(s21_is_less(b, a), 0);  // Ожидаем FALSE

  s21_decimal c = {{-12345, 0, 0, 0x80000000}};  // -12345
  ck_assert_int_eq(s21_is_less(c, a), 1);        // -12345 < +12345
}
END_TEST

Suite *suite_is_less(void) {
  Suite *s = suite_create("suite_is_less");
  TCase *tc = tcase_create("is_less_tc");

  tcase_add_test(tc, test_s21_is_less);

  suite_add_tcase(s, tc);

  return s;
}