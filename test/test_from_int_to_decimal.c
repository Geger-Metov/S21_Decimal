#include "s21_decimal_test.h"

START_TEST(first) {
  s21_decimal val = {0};
  s21_decimal res = {{45869, 0, 0, 0}};
  int src = 45869;

  s21_from_int_to_decimal(src, &val);

  ck_assert_int_eq(val.bits[0], res.bits[0]);
  ck_assert_int_eq(val.bits[1], res.bits[1]);
  ck_assert_int_eq(val.bits[2], res.bits[2]);
  ck_assert_int_eq(val.bits[3], res.bits[3]);
}
END_TEST

START_TEST(second) {
  s21_decimal val = {0};
  s21_decimal res = {{8596, 0, 0, 2147483648U}};
  int src = -8596;

  s21_from_int_to_decimal(src, &val);

  ck_assert_int_eq(val.bits[0], res.bits[0]);
  ck_assert_int_eq(val.bits[1], res.bits[1]);
  ck_assert_int_eq(val.bits[2], res.bits[2]);
  ck_assert_int_eq(val.bits[3], res.bits[3]);
}
END_TEST

Suite *suite_from_int_to_decimal(void) {
  Suite *s = suite_create("suite_from_int_to_decimal");
  TCase *tc = tcase_create("from_int_to_decimal_tc");

  tcase_add_test(tc, first);
  tcase_add_test(tc, second);

  suite_add_tcase(s, tc);

  return s;
}