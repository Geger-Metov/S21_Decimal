#include "s21_decimal.h"

// Проверка на меньше
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int sign1 = (value_1.bits[3] >> 31) & 1;
  int sign2 = (value_2.bits[3] >> 31) & 1;

  // Если знаки разные
  if (sign1 != sign2) {
    return sign1 > sign2;  // Отрицательное число всегда меньше положительного
  }

  // Если знаки одинаковые, сравниваем значения побитно
  for (int i = 3; i >= 0; i--) {
    if (value_1.bits[i] < value_2.bits[i]) {
      return !sign1;  // Если положительное — TRUE, если отрицательное — FALSE
    } else if (value_1.bits[i] > value_2.bits[i]) {
      return sign1;  // Если положительное — FALSE, если отрицательное — TRUE
    }
  }

  return 0;  // Числа равны
}

// Проверка на меньше или равно
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}

// Проверка на больше
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less_or_equal(value_1, value_2);
}

// Проверка на больше или равно
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less(value_1, value_2);
}

// Проверка на равенство
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  // Сравниваем все биты числа
  for (int i = 0; i < 4; i++) {
    if (value_1.bits[i] != value_2.bits[i]) {
      return 0;  // FALSE
    }
  }
  return 1;  // TRUE
}

// Проверка на неравенство
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}