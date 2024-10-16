#include "../s21_test.h"

START_TEST(s21_strtok_test) {
  char strtok_test1[] = "split this string";
  char strtok_delim1[] = " ";
  char strtok_copy1[] = "split this string";
  ck_assert_str_eq(s21_strtok(strtok_test1, strtok_delim1),
                   strtok(strtok_copy1, strtok_delim1));

  char strtok_test2[] = "another,test,string";
  char strtok_delim2[] = ",";
  char strtok_copy2[] = "another,test,string";
  ck_assert_str_eq(s21_strtok(strtok_test2, strtok_delim2),
                   strtok(strtok_copy2, strtok_delim2));

  char *s21_token, *orig_token;
  while ((s21_token = s21_strtok(NULL, strtok_delim2)) &&
         (orig_token = strtok(NULL, strtok_delim2))) {
    ck_assert_str_eq(s21_token, orig_token);
  }
}
END_TEST

START_TEST(STRTOK_BASE_SPLIT) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char one_char_as_string[] = "o";
  char *actual = s21_strtok(simple_phrase, one_char_as_string);
  char *expected = strtok(simple_phrase, one_char_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRTOK_SPLIT_THE_STRING_WITH_SP_CH) {
  const char one_char_as_string[] = "o";
  char phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  char *actual = s21_strtok(phrase_with_sp_ch, one_char_as_string);
  char *expected = strtok(phrase_with_sp_ch, one_char_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRTOK_SPLIT_BY_SPACE) {
  char simple_phrase[100] = "I think it\n must work\n";
  const char space_as_string[] = " ";
  char *actual = s21_strtok(simple_phrase, space_as_string);
  char *expected = strtok(simple_phrase, space_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRTOK_SPLIT_THE_SPACES_BY_SPACE) {
  char space_instead_of_string[] = "       ";
  const char one_char_as_string[] = "o";
  char *actual = s21_strtok(space_instead_of_string, one_char_as_string);
  char *expected = strtok(space_instead_of_string, one_char_as_string);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(STRTOK_SPLIT_BY_STRING) {
  const char almost_equal_one[] = "Equal";
  char almost_equal_three[] = "Equal but";
  char *actual = s21_strtok(almost_equal_three, almost_equal_one);
  char *expected = strtok(almost_equal_three, almost_equal_one);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s1 = suite_create("strtok");
  TCase *tc1_1 = tcase_create("strtok");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_strtok_test);
  tcase_add_test(tc1_1, STRTOK_BASE_SPLIT);
  tcase_add_test(tc1_1, STRTOK_SPLIT_THE_STRING_WITH_SP_CH);
  tcase_add_test(tc1_1, STRTOK_SPLIT_BY_SPACE);
  tcase_add_test(tc1_1, STRTOK_SPLIT_THE_SPACES_BY_SPACE);
  tcase_add_test(tc1_1, STRTOK_SPLIT_BY_STRING);

  return s1;
}
