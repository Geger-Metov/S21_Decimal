#include "test/s21_decimal_test.h"

int main(void) {
  tests();
  return 0;
}

void run_test(Suite *testcase) {
  static int cnt = 1;

  if (cnt > 1) {
    putchar('\n');
  }
  printf("CURRENT TEST: %d\n", cnt);
  cnt++;

  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void tests(void) {
  Suite *test_list[] = {suite_from_int_to_decimal(),
                        suite_negate(),
                        suite_truncate(),
                        suite_is_less(),
                        suite_is_less_or_equal(),
                        suite_is_greater(),
                        suite_is_greater_or_equal(),
                        suite_is_equal(),
                        suite_is_not_equal(),
                        suite_from_decimal_to_int(),
                        suite_from_float_to_decimal(),
                        suite_from_decimal_to_float(),
                        NULL};
  for (Suite **current_testcase = test_list; *current_testcase != NULL;
       current_testcase++) {
    run_test(*current_testcase);
  }
  putchar('\n');
}
