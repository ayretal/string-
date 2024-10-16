#include "../s21_test.h"

START_TEST(s21_strpbrk_test) {
  char strpbrk_test1[] = "hello world";
  char strpbrk_accept1[] = "abcde";
  ck_assert_ptr_eq(s21_strpbrk(strpbrk_test1, strpbrk_accept1),
                   strpbrk(strpbrk_test1, strpbrk_accept1));

  char strpbrk_test2[] = "test string";
  char strpbrk_accept2[] = "xyz";
  ck_assert_ptr_null(s21_strpbrk(strpbrk_test2, strpbrk_accept2));

  char strpbrk_test3[] = "123456789";
  char strpbrk_accept3[] = "987";
  ck_assert_ptr_eq(s21_strpbrk(strpbrk_test3, strpbrk_accept3),
                   strpbrk(strpbrk_test3, strpbrk_accept3));
}
END_TEST

START_TEST(STRPBRK_FIND_THE_ONE_CH_IN_STRING) {
  const char simple_phrase[100] = "I think it\n must work\n";
  const char one_char_as_string[] = "o";
  char *actual = s21_strpbrk(simple_phrase, one_char_as_string);
  char *expected = strpbrk(simple_phrase, one_char_as_string);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(STRPBRK_FIND_THE_MISSING_CH_IN_STRING) {
  char missing_char_as_string[] = "x";
  char simple_phrase[100] = "I think it\n must work\n";
  char *actual = s21_strpbrk(simple_phrase, missing_char_as_string);
  char *expected = strpbrk(simple_phrase, missing_char_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRPBRK_FIND_THE_WORD_IN_STRING) {
  const char word[10] = "must";
  const char simple_phrase[100] = "I think it\n must work\n";
  char *actual = s21_strpbrk(simple_phrase, word);
  char *expected = strpbrk(simple_phrase, word);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(STRPBRK_FIND_THE_STRING_IN_THE_SAME_STRING) {
  const char simple_phrase[100] = "I think it\n must work\n";
  char *actual = s21_strpbrk(simple_phrase, simple_phrase);
  char *expected = strpbrk(simple_phrase, simple_phrase);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(STRPBRK_FIND_THE_SP_CH_IN_STRING) {
  const char simple_phrase[100] = "I think it\n must work\n";
  const char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  char *actual = s21_strpbrk(simple_phrase, phrase_with_sp_ch);
  char *expected = strpbrk(simple_phrase, phrase_with_sp_ch);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(STRPBRK_FIND_THE_EMPTY_STRING_IN_NORMAL_STRING) {
  char simple_phrase[100] = "I think it\n must work\n";
  char empty_string[100] = "";
  char *actual = s21_strpbrk(simple_phrase, empty_string);
  char *expected = strpbrk(simple_phrase, empty_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRPBRK_FIND_THE_WORD_IN_EMPTY_STRING) {
  char word[10] = "Hello";
  char empty_string[100] = "";
  char *actual = s21_strpbrk(empty_string, word);
  char *expected = strpbrk(empty_string, word);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s1 = suite_create("strpbrk");
  TCase *tc1_1 = tcase_create("strpbrk");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, STRPBRK_FIND_THE_ONE_CH_IN_STRING);
  tcase_add_test(tc1_1, STRPBRK_FIND_THE_MISSING_CH_IN_STRING);
  tcase_add_test(tc1_1, STRPBRK_FIND_THE_WORD_IN_STRING);
  tcase_add_test(tc1_1, STRPBRK_FIND_THE_STRING_IN_THE_SAME_STRING);
  tcase_add_test(tc1_1, STRPBRK_FIND_THE_SP_CH_IN_STRING);
  tcase_add_test(tc1_1, STRPBRK_FIND_THE_EMPTY_STRING_IN_NORMAL_STRING);
  tcase_add_test(tc1_1, STRPBRK_FIND_THE_WORD_IN_EMPTY_STRING);

  return s1;
}