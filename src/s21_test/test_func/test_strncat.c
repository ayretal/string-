#include "../s21_test.h"

START_TEST(STRNCAT_ADD_ONE_STRING_TO_THE_END_OF_ANOTHER) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char word[10] = "Hello";
  char *actual = s21_strncat(simple_phrase, word, 4);
  char *expected = strncat(simple_phrase, word, 4);
  ck_assert_uint_eq((long)actual, (long)expected);
}
END_TEST

START_TEST(STRNCAT_ADD_STRING_TO_THE_EMPTY_STRING) {
  char big_empty_string[100] = {0};
  const char word[10] = "Hello";
  char *actual = s21_strncat(big_empty_string, word, 4);
  char *expected = strncat(big_empty_string, word, 4);
  ck_assert_uint_eq((long)actual, (long)expected);
}
END_TEST

START_TEST(STRNCAT_ADD_STRING_WITH_DIF_CH_TO_EMPTY_STRING) {
  char big_empty_string[100] = {0};
  const char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  char *actual = s21_strncat(big_empty_string, phrase_with_sp_ch, 4);
  char *expected = strncat(big_empty_string, phrase_with_sp_ch, 4);
  ck_assert_uint_eq((long)actual, (long)expected);
}
END_TEST

START_TEST(STRNCAT_ADD_STRING_TO_THE_STRING_WITH_DIF_CH) {
  char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  const char word[10] = "Hello";
  char *actual = s21_strncat(phrase_with_sp_ch, word, 4);
  char *expected = strncat(phrase_with_sp_ch, word, 4);
  ck_assert_uint_eq((long)actual, (long)expected);
}
END_TEST

START_TEST(STRNCAT_ADD_EMPTY_STRING_TO_THE_NORMAL_STRING) {
  const char empty_string[100] = "";
  char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  char *actual = s21_strncat(phrase_with_sp_ch, empty_string, 4);
  char *expected = strncat(phrase_with_sp_ch, empty_string, 4);
  ck_assert_uint_eq((long)actual, (long)expected);
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s1 = suite_create("strncat");
  TCase *tc1_1 = tcase_create("strncat");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, STRNCAT_ADD_ONE_STRING_TO_THE_END_OF_ANOTHER);
  tcase_add_test(tc1_1, STRNCAT_ADD_STRING_TO_THE_EMPTY_STRING);
  tcase_add_test(tc1_1, STRNCAT_ADD_STRING_WITH_DIF_CH_TO_EMPTY_STRING);
  tcase_add_test(tc1_1, STRNCAT_ADD_STRING_TO_THE_STRING_WITH_DIF_CH);
  tcase_add_test(tc1_1, STRNCAT_ADD_EMPTY_STRING_TO_THE_NORMAL_STRING);

  return s1;
}
