#include "s21_decimal_test.h"

START_TEST(first) {
  s21_decimal val_1 = {{10000, 0, 0, 262144U}};
  s21_decimal val_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0}};

  s21_truncate(val_1, &val_2);

  ck_assert_int_eq(val_2.bits[0], res.bits[0]);
  ck_assert_int_eq(val_2.bits[1], res.bits[1]);
  ck_assert_int_eq(val_2.bits[2], res.bits[2]);
  ck_assert_int_eq(val_2.bits[3], res.bits[3]);
}

END_TEST

START_TEST(second) {
  s21_decimal val_1 = {{10000, 0, 0, 2147745795U}};
  s21_decimal val_2 = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 2147483648U}};

  s21_truncate(val_1, &val_2);

  ck_assert_int_eq(val_2.bits[0], res.bits[0]);
  ck_assert_int_eq(val_2.bits[1], res.bits[1]);
  ck_assert_int_eq(val_2.bits[2], res.bits[2]);
  ck_assert_int_eq(val_2.bits[3], res.bits[3]);
}

Suite *suite_truncate(void) {
  Suite *s = suite_create("suite_truncate");
  TCase *tc = tcase_create("truncate_tc");

  tcase_add_test(tc, first);
  tcase_add_test(tc, second);

  suite_add_tcase(s, tc);

  return s;
}