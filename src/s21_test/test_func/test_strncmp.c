#include "../s21_test.h"

START_TEST(STRNCMP_COMPARE_EQUAL_SENTENSES) {
  const char simple_phrase[100] = "I think it\n must work\n";
  const char simple_phrase_two[100] = "I think it\n must work\n";
  int actual = s21_strncmp(simple_phrase, simple_phrase_two, 40);
  int expected = strncmp(simple_phrase, simple_phrase_two, 40);
  ck_assert_uint_eq(actual, expected);
}
END_TEST

START_TEST(STRNCMP_COMPARE_DIFFERENT_SENTENSES) {
  const char simple_phrase[100] = "I think it\n must work\n";
  const char word[100] = "Hello";
  int actual = s21_strncmp(simple_phrase, word, 40);
  int expected = strncmp(simple_phrase, word, 40);
  ck_assert_uint_eq(actual, expected);
}
END_TEST

START_TEST(STRNCMP_COMPARE_EQUAL_CH_IN_DIFF_SENTENSES) {
  const char almost_equal_one[100] = "Equal";
  const char almost_equal_two[100] = "Equat";
  int actual = s21_strncmp(almost_equal_one, almost_equal_two, 40);
  int expected = strncmp(almost_equal_one, almost_equal_two, 40);
  ck_assert_uint_eq(actual, expected);
}
END_TEST

START_TEST(STRNCMP_COMPARE_EMPTY_STRINGS) {
  const char big_empty_string[100] = {0};
  const char big_empty_string_two[100] = {0};
  int actual = s21_strncmp(big_empty_string, big_empty_string_two, 40);
  int expected = strncmp(big_empty_string, big_empty_string_two, 40);
  ck_assert_uint_eq(actual, expected);
}
END_TEST

START_TEST(STRNCMP_COMPARE_STRINGS_WITH_DIFFERENT_SIZE) {
  const char empty_string[100] = "";
  const char empty_string_two[100] = "";
  int actual = s21_strncmp(empty_string, empty_string_two, 40);
  int expected = strncmp(empty_string, empty_string_two, 40);
  ck_assert_uint_eq(actual, expected);
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s1 = suite_create("strncmp");
  TCase *tc1_1 = tcase_create("strncmp");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, STRNCMP_COMPARE_EQUAL_SENTENSES);
  tcase_add_test(tc1_1, STRNCMP_COMPARE_DIFFERENT_SENTENSES);
  tcase_add_test(tc1_1, STRNCMP_COMPARE_EQUAL_CH_IN_DIFF_SENTENSES);
  tcase_add_test(tc1_1, STRNCMP_COMPARE_EMPTY_STRINGS);
  tcase_add_test(tc1_1, STRNCMP_COMPARE_STRINGS_WITH_DIFFERENT_SIZE);

  return s1;
}