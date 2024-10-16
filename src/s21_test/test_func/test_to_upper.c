#include "../s21_test.h"
/*
START_TEST(TO_UPPER_BASE) {
  char upper[] = "SOME WORDS";
  char lower[] = "some words";
  void *actual = s21_to_upper(lower);
  void *expected = upper;
  ck_assert_ptr_eq(actual, expected);
}
END_TEST
*/
START_TEST(s21_to_upper_test) {
  const char str_1[] = "All you NEED is Love";
  const char str_2[] = "AbRaKaDaBrA";
  char *result = s21_to_upper(str_1);

  if (result) {
    ck_assert_str_eq(result, "ALL YOU NEED IS LOVE");
    free(result);
  }

  result = s21_to_upper(str_2);

  if (result) {
    ck_assert_str_eq(result, "ABRAKADABRA");
    free(result);
  }
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s1 = suite_create("to_upper");
  TCase *tc1_1 = tcase_create("to_upper");

  suite_add_tcase(s1, tc1_1);
  // tcase_add_test(tc1_1, TO_UPPER_BASE);
  tcase_add_test(tc1_1, s21_to_upper_test);
  return s1;
}