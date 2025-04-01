#include "s21_decimal_test.h"

START_TEST(first) {
  float src = 485.894f;
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_decimal res = {{4858940, 0, 0, 131072}};

  s21_from_float_to_decimal(src, &dst);

  ck_assert_int_eq(dst.bits[0], res.bits[0]);
  ck_assert_int_eq(dst.bits[1], res.bits[1]);
  ck_assert_int_eq(dst.bits[2], res.bits[2]);
  ck_assert_int_eq(dst.bits[3], res.bits[3]);
}
END_TEST

START_TEST(negative) {
  float src = -1459.9864862f;
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_decimal res = {{1459986, 0, 0, 2147680256U}};

  s21_from_float_to_decimal(src, &dst);

  ck_assert_int_eq(dst.bits[0], res.bits[0]);
  ck_assert_int_eq(dst.bits[1], res.bits[1]);
  ck_assert_int_eq(dst.bits[2], res.bits[2]);
  ck_assert_int_eq(dst.bits[3], res.bits[3]);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s = suite_create("suite_from_float_to_decimal");
  TCase *tc = tcase_create("from_float_to_decimal_tc");

  tcase_add_test(tc, first);
  tcase_add_test(tc, negative);

  suite_add_tcase(s, tc);

  return s;
}

// Тест на ноль:
//
// Вход: src = 0.0
// Ожидаемый результат: dst должен содержать 0 (мантисса и порядок равны нулю).

// Тест на очень маленькое положительное число:
//
// Вход: src = 1e-30
// Ожидаемый результат: res должен быть равен 1 (число слишком мало для
// представления).

// Тест на очень маленькое отрицательное число:
//
//  Вход: src = -1e-30
//  Ожидаемый результат: res должен быть равен 1 (число слишком мало для
//  представления).

// Тест на бесконечность:
//
//  Вход: src = INFINITY
//  Ожидаемый результат: res должен быть равен 1 (бесконечность не может быть
//  представлена).

// Тест на NaN (не число):
//
//   Вход: src = NAN
//   Ожидаемый результат: res должен быть равен 1 (NaN не может быть
//   представлено).

// Тест на число с большим порядком:
//
//    Вход: src = 1.23456789e+10
//    Ожидаемый результат: dst должен содержать корректное представление числа
//    12345678900 с порядком 0.

// Тест на число с большим отрицательным порядком:
//
//     Вход: src = 0.000000123456
//     Ожидаемый результат: dst должен содержать корректное представление числа
//     123456 с порядком -9.

// Тест на число с точностью:
//
//      Вход: src = 3.14159265359
//      Ожидаемый результат: dst должен содержать корректное представление числа
//      314159265359 с порядком -11.