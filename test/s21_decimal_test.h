#ifndef S21_DECIMAL_TEST_H
#define S21_DECIMAL_TEST_H

#include <check.h>
#include <float.h>

#include "../s21_decimal.h"

// converter
Suite *suite_from_int_to_decimal(void);
Suite *suite_from_decimal_to_int(void);
Suite *suite_from_float_to_decimal(void);
Suite *suite_from_decimal_to_float(void);

// other
Suite *suite_negate(void);
Suite *suite_truncate(void);

// comparison
Suite *suite_is_less(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_equal(void);
Suite *suite_is_not_equal(void);

void run_test(Suite *testcase);
void tests(void);

#endif