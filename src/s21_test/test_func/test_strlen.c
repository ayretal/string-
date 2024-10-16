#include "../s21_test.h"

START_TEST(STRLEN_CALCULATE_THE_LENGHT_OF_WORD) {
  const char word[10] = "Hello";
  s21_size_t actual = s21_strlen(word);
  s21_size_t expected = strlen(word);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

START_TEST(STRLEN_CALCULATE_THE_LENGHT_OF_SENTENSE) {
  const char simple_phrase[100] = "I think it\n must work\n";
  s21_size_t actual = s21_strlen(simple_phrase);
  s21_size_t expected = strlen(simple_phrase);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

START_TEST(STRLEN_CALCULATE_THE_LENGHT_OF_STRING_WITH_SP_CH) {
  const char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  s21_size_t actual = s21_strlen(phrase_with_sp_ch);
  s21_size_t expected = strlen(phrase_with_sp_ch);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

START_TEST(STRLEN_CALCULATE_THE_LENGHT_OF_EMPTY_STRING) {
  const char empty_string[100] = "";
  s21_size_t actual = s21_strlen(empty_string);
  s21_size_t expected = strlen(empty_string);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

START_TEST(STRLEN_CALCULATE_THE_LENGHT_OF_STRING_FROM_SPACES) {
  const char space_instead_of_string[] = "       ";
  s21_size_t actual = s21_strlen(space_instead_of_string);
  s21_size_t expected = strlen(space_instead_of_string);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s1 = suite_create("strlen");
  TCase *tc1_1 = tcase_create("strlen");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, STRLEN_CALCULATE_THE_LENGHT_OF_WORD);
  tcase_add_test(tc1_1, STRLEN_CALCULATE_THE_LENGHT_OF_SENTENSE);
  tcase_add_test(tc1_1, STRLEN_CALCULATE_THE_LENGHT_OF_STRING_WITH_SP_CH);
  tcase_add_test(tc1_1, STRLEN_CALCULATE_THE_LENGHT_OF_EMPTY_STRING);
  tcase_add_test(tc1_1, STRLEN_CALCULATE_THE_LENGHT_OF_STRING_FROM_SPACES);
  return s1;
}