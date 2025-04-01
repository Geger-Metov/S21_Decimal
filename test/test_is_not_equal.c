#include "s21_decimal_test.h"

START_TEST(test_s21_is_not_equal) {
  s21_decimal a = {{12345, 0, 0, 0}};           // 12345
  s21_decimal b = {{54322, 0, 0, 0}};           // 54322
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);  // Ожидаем TRUE

  b.bits[0] = a.bits[0];                        // Теперь b равно a
  ck_assert_int_eq(s21_is_not_equal(a, b), 0);  // Ожидаем FALSE
}
END_TEST

Suite *suite_is_not_equal(void) {
  Suite *s = suite_create("suite_is_not_equal");
  TCase *tc = tcase_create("is_not_equal_tc");

  tcase_add_test(tc, test_s21_is_not_equal);

  suite_add_tcase(s, tc);

  return s;
}