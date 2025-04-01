#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;

  if (!dst) {
    res = 1;
  } else {
    s21_clear_decimal(dst);

    if (src < 0) {
      s21_set_sign(dst, 1);
      src = -src;
    }
    if (src > INT_MAX || src < INT_MIN) {
      res = 1;
    } else {
      dst->bits[0] = src;
    }
  }
  return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;

  if (!dst) {
    res = 1;
  } else if (src.bits[1] || src.bits[2] || src.bits[0] > INT_MAX) {
    res = 1;
  } else {
    s21_decimal tmp = src;
    s21_truncate(src, &tmp);
    *dst = tmp.bits[0];
    if (s21_get_sign(src)) {
      *dst *= -1;
    }
  }
  return res;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  if (!dst) {
    res = 1;
  } else if (fabs(src) < 1e-28 && fabs(src) > 0) {
    res = 1;
  } else if (isinf(src) || isnan(src)) {
    res = 1;
  } else {
    int sign = 0;
    if (src < 0) {
      sign = 1;
      src *= -1;
    }
    s21_decimal tmp;
    s21_clear_decimal(&tmp);
    char str[100];
    snprintf(str, sizeof(str), "%.6E", src);

    int cnt = float_cnt_degree(str);
    tmp = from_str_to_decimal(str);

    set_degree(&tmp, cnt);
    s21_set_sign(&tmp, sign);

    *dst = tmp;
  }
  return res;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  if (!dst) {
    res = 1;
  } else {
    *dst = 0.0;
    double tmp = 0.0;
    int sign = s21_get_sign(src);
    int degree = get_number_degree(src);

    for (int i = 0; i < 96; i++) {
      if (s21_decimal_is_set_bit(src, i)) {
        tmp += pow(2, i);
      }
    }
    tmp /= pow(10, degree);

    if (sign) {
      tmp *= -1.0;
    }
    *dst = (float)tmp;
  }
  return res;
}