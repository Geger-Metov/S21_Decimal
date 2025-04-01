#include "s21_decimal_test.h"

START_TEST(first) {
  s21_decimal val_1 = {
      {10, 0, 0,
       2147483648U}};  // 2147483648 == 0b10000000000000000000000000000000
  s21_decimal val_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{10, 0, 0, 0}};

  s21_negate(val_1, &val_2);

  ck_assert_int_eq(val_2.bits[0], res.bits[0]);
  ck_assert_int_eq(val_2.bits[1], res.bits[1]);
  ck_assert_int_eq(val_2.bits[2], res.bits[2]);
  ck_assert_int_eq(val_2.bits[3], res.bits[3]);
}
END_TEST

START_TEST(second) {
  s21_decimal val_1 = {{3254, 0, 0, 0}};
  s21_decimal val_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{3254, 0, 0, 2147483648U}};

  s21_negate(val_1, &val_2);

  ck_assert_int_eq(val_2.bits[0], res.bits[0]);
  ck_assert_int_eq(val_2.bits[1], res.bits[1]);
  ck_assert_int_eq(val_2.bits[2], res.bits[2]);
  ck_assert_int_eq(val_2.bits[3], res.bits[3]);
}
END_TEST

Suite *suite_negate(void) {
  Suite *s = suite_create("suite_negate");
  TCase *tc = tcase_create("negate_tc");

  tcase_add_test(tc, first);
  tcase_add_test(tc, second);

  suite_add_tcase(s, tc);

  return s;
}