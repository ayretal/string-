#include "../s21_test.h"

START_TEST(STRCSPN_COMPARE_TWO_ALMOST_EQUAL_STRING) {
  char const almost_equal_one[] = "Equal";
  char const almost_equal_two[] = "Equat";
  s21_size_t actual = s21_strcspn(almost_equal_one, almost_equal_two);
  s21_size_t expected = strcspn(almost_equal_one, almost_equal_two);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

START_TEST(STRCSPN_COMPARE_COMPLETLELY_DIFFERENT_STRINGS) {
  char const almost_equal_one[] = "Equal";
  char const empty_string[100] = "";
  s21_size_t actual = s21_strcspn(almost_equal_one, empty_string);
  s21_size_t expected = strcspn(almost_equal_one, empty_string);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

START_TEST(STRCSPN_COMPARE_TWO_EMPTY_STRINGS) {
  char const empty_string[100] = "";
  s21_size_t actual = s21_strcspn(empty_string, empty_string);
  s21_size_t expected = strcspn(empty_string, empty_string);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

START_TEST(STRCSPN_COMPARE_WITH_SPECIAL_CHARACTERS) {
  char const simple_phrase[100] = "I think it\n must work\n";
  char const phrase_with_sp_ch[100] = "|;1_ .,!@o#$^&*()+=";
  s21_size_t actual = s21_strcspn(phrase_with_sp_ch, simple_phrase);
  s21_size_t expected = strcspn(phrase_with_sp_ch, simple_phrase);
  ck_assert_uint_eq((int)actual, (int)expected);
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s1 = suite_create("strcspn");
  TCase *tc1_1 = tcase_create("strcspn");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, STRCSPN_COMPARE_TWO_ALMOST_EQUAL_STRING);
  tcase_add_test(tc1_1, STRCSPN_COMPARE_COMPLETLELY_DIFFERENT_STRINGS);
  tcase_add_test(tc1_1, STRCSPN_COMPARE_TWO_EMPTY_STRINGS);
  tcase_add_test(tc1_1, STRCSPN_COMPARE_WITH_SPECIAL_CHARACTERS);

  return s1;
}