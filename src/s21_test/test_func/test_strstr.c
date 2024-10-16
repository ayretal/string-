#include "../s21_test.h"

START_TEST(s21_strstr_test) {
  char strstr_haystack1[] = "search within this string";
  char strstr_needle1[] = "within";
  ck_assert_ptr_eq(s21_strstr(strstr_haystack1, strstr_needle1),
                   strstr(strstr_haystack1, strstr_needle1));

  char strstr_haystack2[] = "find me if you can";
  char strstr_needle2[] = "you";
  ck_assert_ptr_eq(s21_strstr(strstr_haystack2, strstr_needle2),
                   strstr(strstr_haystack2, strstr_needle2));

  char strstr_haystack3[] = "no matching substring here";
  char strstr_needle3[] = "substring";
  ck_assert_ptr_eq(s21_strstr(strstr_haystack3, strstr_needle3),
                   strstr(strstr_haystack3, strstr_needle3));
}
END_TEST

START_TEST(STRSTR_FIND_THE_CH_IN_SENTENSE) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char one_char_as_string[] = "o";
  char *actual = s21_strstr(simple_phrase, one_char_as_string);
  char *expected = strstr(simple_phrase, one_char_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRSTR_FIND_THE_CH_IN_SENTENSE_WITH_SP_CH) {
  char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  const char one_char_as_string[] = "o";
  char *actual = s21_strstr(phrase_with_sp_ch, one_char_as_string);
  char *expected = strstr(phrase_with_sp_ch, one_char_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRSTR_FIND_THE_MISSING_CH_IN_STRING) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char missing_char_as_string[] = "x";
  char *actual = s21_strstr(simple_phrase, missing_char_as_string);
  char *expected = strstr(simple_phrase, missing_char_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRSTR_FIND_THE_SPACE_IN_STRING) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char space_instead_of_string[] = "       ";
  char *actual = s21_strstr(simple_phrase, space_instead_of_string);
  char *expected = strstr(simple_phrase, space_instead_of_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s1 = suite_create("strstr");
  TCase *tc1_1 = tcase_create("strstr");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, STRSTR_FIND_THE_CH_IN_SENTENSE);
  tcase_add_test(tc1_1, STRSTR_FIND_THE_CH_IN_SENTENSE_WITH_SP_CH);
  tcase_add_test(tc1_1, STRSTR_FIND_THE_MISSING_CH_IN_STRING);
  tcase_add_test(tc1_1, STRSTR_FIND_THE_SPACE_IN_STRING);

  return s1;
}