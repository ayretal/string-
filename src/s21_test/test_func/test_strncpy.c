#include "../s21_test.h"

START_TEST(STRNCPY_COPY_WORD_IN_SENTENSE) {
  const char word[10] = "Hello";
  char simple_phrase[100] = "I think it\n must work\n";
  char *actual = s21_strncpy(simple_phrase, word, 4);
  char *expected = strncpy(simple_phrase, word, 4);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRNCPY_COPY_EMPTY_STRING_IN_SENTENSE) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char empty_string[100] = "";
  char *actual = s21_strncpy(simple_phrase, empty_string, 4);
  char *expected = strncpy(simple_phrase, empty_string, 4);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRNCPY_COPY_SPACES_IN_SENTENSE) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char space_instead_of_string[] = "       ";
  char *actual = s21_strncpy(simple_phrase, space_instead_of_string, 4);
  char *expected = strncpy(simple_phrase, space_instead_of_string, 4);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRNCPY_COPY_WORD_IN_EMPTY_SHORT_STRING) {
  char empty_string[100] = "";
  const char word[10] = "Hello";
  char *actual = s21_strncpy(empty_string, word, 4);
  char *expected = strncpy(empty_string, word, 4);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRNCPY_COPY_LARGE_STRING_IN_SHORT_STRING) {
  char word[10] = "Hello";
  const char simple_phrase[100] = "I think it\n must work\n";
  char *actual = s21_strncpy(word, simple_phrase, 4);
  char *expected = strncpy(word, simple_phrase, 4);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(STRNCPY_COPY_SP_CH_IN_ANOTHER_STRING) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  char *actual = s21_strncpy(simple_phrase, phrase_with_sp_ch, 4);
  char *expected = strncpy(simple_phrase, phrase_with_sp_ch, 4);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s1 = suite_create("strncpy");
  TCase *tc1_1 = tcase_create("strncpy");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, STRNCPY_COPY_WORD_IN_SENTENSE);
  tcase_add_test(tc1_1, STRNCPY_COPY_EMPTY_STRING_IN_SENTENSE);
  tcase_add_test(tc1_1, STRNCPY_COPY_SPACES_IN_SENTENSE);
  tcase_add_test(tc1_1, STRNCPY_COPY_WORD_IN_EMPTY_SHORT_STRING);
  tcase_add_test(tc1_1, STRNCPY_COPY_LARGE_STRING_IN_SHORT_STRING);
  tcase_add_test(tc1_1, STRNCPY_COPY_SP_CH_IN_ANOTHER_STRING);

  return s1;
}
