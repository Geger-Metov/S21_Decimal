#include "s21_decimal_test.h"

START_TEST(test_s21_is_equal) {
  s21_decimal a = {{12345, 0, 0, 0}};       // 12345
  s21_decimal b = {{12345, 0, 0, 0}};       // 12345
  ck_assert_int_eq(s21_is_equal(a, b), 1);  // Ожидаем TRUE

  b.bits[0] = 54321;                        // Изменяем b на 54321
  ck_assert_int_eq(s21_is_equal(a, b), 0);  // Ожидаем FALSE
}
END_TEST

Suite *suite_is_equal(void) {
  Suite *s = suite_create("suite_is_equal");
  TCase *tc = tcase_create("is_equal_tc");

  tcase_add_test(tc, test_s21_is_equal);

  suite_add_tcase(s, tc);

  return s;
}