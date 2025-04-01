#include "s21_decimal_test.h"

START_TEST(first) {
  s21_decimal src = {{2147489, 0, 0, 65536}};
  float dst;
  float res = 214748.9;

  s21_from_decimal_to_float(src, &dst);

  ck_assert_float_eq(dst, res);
}
END_TEST

Suite *suite_from_decimal_to_float(void) {
  Suite *s = suite_create("suite_from_decimal_to_float");
  TCase *tc = tcase_create("from_decimal_to_float_tc");

  tcase_add_test(tc, first);

  suite_add_tcase(s, tc);

  return s;
}