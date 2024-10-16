#include "../s21_test.h"

START_TEST(STRCHR_SEARCH_CH_IN_ONE_WORD) {
  const char word[10] = "Hello";
  char one_char = 'o';
  char *actual = s21_strchr(word, one_char);
  char *expected = strchr(word, one_char);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRCHR_SEARCH_CH_IN_SENTENSE) {
  const char simple_phrase[100] = "I think it\n must work\n";
  char one_char = 'o';
  char *actual = s21_strchr(simple_phrase, one_char);
  char *expected = strchr(simple_phrase, one_char);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRCHR_SEARCH_CH_IN_SENTENSE_WITH_SP_CH) {
  char one_char = 'o';
  char const phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  char *actual = s21_strchr(phrase_with_sp_ch, one_char);
  char *expected = strchr(phrase_with_sp_ch, one_char);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRCHR_SEARCH_MISSING_CH_IN_SENTENSE) {
  char missing_char = 'x';
  char const phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  char *actual = s21_strchr(phrase_with_sp_ch, missing_char);
  char *expected = strchr(phrase_with_sp_ch, missing_char);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s1 = suite_create("strchr");
  TCase *tc1_1 = tcase_create("strchr");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, STRCHR_SEARCH_CH_IN_ONE_WORD);
  tcase_add_test(tc1_1, STRCHR_SEARCH_CH_IN_SENTENSE);
  tcase_add_test(tc1_1, STRCHR_SEARCH_CH_IN_SENTENSE_WITH_SP_CH);
  tcase_add_test(tc1_1, STRCHR_SEARCH_MISSING_CH_IN_SENTENSE);
  return s1;
}