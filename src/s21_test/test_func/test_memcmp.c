#include "../s21_test.h"

START_TEST(COMPARE_EQUAL_WORD) {
  const char str[50] = "Hello";
  const char str_two[50] = "Hello";
  int actual = s21_memcmp(str, str_two, 40);
  int expected = memcmp(str, str_two, 40);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(COMPARE_EQUAL_SENTENSES) {
  const char str[50] = "I think it must \n work";
  const char str_two[50] = "I think it must \n work";
  int actual = s21_memcmp(str, str_two, 40);
  int expected = memcmp(str, str_two, 40);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(COMPARE_SHORT_WITH_LONG_SENTENSES) {
  const char str[50] = "Hello";
  const char str_two[50] = "I think it must \n work";
  int actual = s21_memcmp(str, str_two, 40);
  int expected = memcmp(str, str_two, 40);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(COMPARE_LONG_WITH_SHORT_SENTENSES) {
  const char str[50] = "Hello";
  const char str_two[50] = "I think it must \n work";
  int actual = s21_memcmp(str, str_two, 40);
  int expected = memcmp(str, str_two, 40);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(COMPARE_WITH_EMPTY_STRING) {
  const char str[50] = "I think it must \n work";
  char const empty_stirng[50] = "";
  int actual = s21_memcmp(str, empty_stirng, 40);
  int expected = memcmp(str, empty_stirng, 40);
  ck_assert_int_eq((actual > 0), (expected > 0));
}
END_TEST

START_TEST(COMPARE_EQUAL_SIZE_SENTENSES_WITH_DIFF_CH) {
  const char str[50] = "Equal";
  const char str_two[50] = "Equat";

  int actual = s21_memcmp(str, str_two, 40);
  int expected = memcmp(str, str_two, 40);
  ck_assert_int_eq((actual < 0), (expected < 0));
}
END_TEST

START_TEST(COMPARE_SENTENSES_UNTIL_DIFFERENSES) {
  const char str[50] = "Equal";
  const char str_two[50] = "Equal but";
  int actual = s21_memcmp(str, str_two, 40);
  int expected = memcmp(str, str_two, 40);
  ck_assert_int_eq((actual < 0), (expected < 0));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s2 = suite_create("memcmp");
  TCase *tc2_1 = tcase_create("memcmp");
  suite_add_tcase(s2, tc2_1);
  tcase_add_test(tc2_1, COMPARE_EQUAL_WORD);
  tcase_add_test(tc2_1, COMPARE_EQUAL_SENTENSES);
  tcase_add_test(tc2_1, COMPARE_SHORT_WITH_LONG_SENTENSES);
  tcase_add_test(tc2_1, COMPARE_LONG_WITH_SHORT_SENTENSES);
  tcase_add_test(tc2_1, COMPARE_WITH_EMPTY_STRING);
  tcase_add_test(tc2_1, COMPARE_EQUAL_SIZE_SENTENSES_WITH_DIFF_CH);
  tcase_add_test(tc2_1, COMPARE_SENTENSES_UNTIL_DIFFERENSES);
  return s2;
}