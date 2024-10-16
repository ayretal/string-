#include "../s21_test.h"

START_TEST(CHECK_THE_ERROR_LIST_IN_CYCLE) {
  int count = 0;
  int size_of_arr = 107;

  while (count < size_of_arr) {
    char *actual = s21_strerror(count);
    char *expected = strerror(count);
    ck_assert_str_eq(actual, expected);
    count++;
  }
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s1 = suite_create("strerror");
  TCase *tc1_1 = tcase_create("strerror");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, CHECK_THE_ERROR_LIST_IN_CYCLE);

  return s1;
}
