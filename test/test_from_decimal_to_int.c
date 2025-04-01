#include "s21_decimal_test.h"

START_TEST(first) {
  s21_decimal src = {{21, 0, 0, 0}};
  int val = 0;
  int res = 21;

  s21_from_decimal_to_int(src, &val);

  ck_assert_int_eq(val, res);
}
END_TEST

START_TEST(second) {
  s21_decimal src = {{2112, 0, 0, 131072}};
  int val = 0;
  int res = 21;

  s21_from_decimal_to_int(src, &val);

  ck_assert_int_eq(val, res);
}

START_TEST(third) {
  s21_decimal src = {{1387, 0, 0, 2147483648U}};
  int val = 0;
  int res = -1387;

  s21_from_decimal_to_int(src, &val);

  ck_assert_int_eq(val, res);
}

Suite *suite_from_decimal_to_int(void) {
  Suite *s = suite_create("suite_from_decimal_to_int");
  TCase *tc = tcase_create("from_decimal_to_int_tc");

  tcase_add_test(tc, first);
  tcase_add_test(tc, second);
  tcase_add_test(tc, third);

  suite_add_tcase(s, tc);

  return s;
}