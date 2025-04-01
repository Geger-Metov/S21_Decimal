#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

// typedef struct {
//   unsigned int bits[8];
// } s21_big_decimal;

// arithmetic
// int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// comparison
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// conversion
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// other
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// helpers
void s21_clear_decimal(s21_decimal *dst);
void s21_set_sign(s21_decimal *dst, int sign);
int s21_get_sign(s21_decimal dst);
int get_number_degree(s21_decimal dst);
int isNull(s21_decimal dec);
int ten_div(int bit);
int float_cnt_degree(char *str);
s21_decimal from_str_to_decimal(char *str);
int set_degree(s21_decimal *dst, int degree);
int is_set_bit(int number, int index);
int s21_decimal_is_set_bit(s21_decimal decimal, int index);

#endif