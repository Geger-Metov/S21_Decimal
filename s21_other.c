#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;

  if (!result) {
    res = 1;
  } else {
    int sign = s21_get_sign(value);
    int num_degree = get_number_degree(value);
    s21_decimal tmp = value;
    tmp.bits[3] = 0;
    // в дальнейшем заменить s21_div
    while (num_degree > 0) {
      if (tmp.bits[2] > 0) {
        tmp.bits[2] = ten_div(tmp.bits[2]);
      } else if (tmp.bits[1] > 0) {
        tmp.bits[1] = ten_div(tmp.bits[1]);
      } else if (tmp.bits[0] > 0) {
        tmp.bits[0] = ten_div(tmp.bits[0]);
      }
      num_degree--;
    }
    s21_set_sign(&tmp, sign);
    *result = tmp;
  }
  return res;
}

// 0000000 00000000 00000000 00000000

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int sign = s21_get_sign(value);
  if (!result) {
    res = 1;
  } else {
    *result = value;
    if (sign == 0) {
      s21_set_sign(result, 1);
    } else {
      s21_set_sign(result, 0);
    }
  }
  return res;
}