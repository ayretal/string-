#include "../s21_test.h"

START_TEST(SEARCH_CHAR_IN_ONE_WORD) {
  void *actual = s21_memchr("Word", 'o', 40);
  void *expected = memchr("Word", 'o', 40);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(SEARCH_CHAR_IN_SENTENSE) {
  void *actual = s21_memchr("I think it must \n work", 'o', 40);
  void *expected = memchr("I think it must \n work", 'o', 40);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(SEARCH_CHAR_IN_DIFFICULT_SENTENSE) {
  void *actual = s21_memchr("|;1_ ,. !@#$%^&**()++~", 'o', 40);
  void *expected = memchr("|;1_ ,. !@#$%^&**()++~", 'o', 40);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(SEARCH_CHAR_IN_EMPTY_STRING) {
  // char empty_stirng[100] = NULL;
  char empty_stirng[100];
  void *actual = s21_memchr(empty_stirng, 'o', 40);
  void *expected = memchr(empty_stirng, 'o', 40);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(SEARCH_CHAR_IN_STRING_FROM_SPACES) {
  void *actual = s21_memchr("         ", 'o', 40);
  void *expected = memchr("         ", 'o', 40);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(SEARCH_MISSING_CHAR_IN_SENTENSE) {
  void *actual = s21_memchr("I think it must \n work", 'x', 40);
  void *expected = memchr("I think it must \n work", 'x', 40);
  ck_assert_ptr_eq(actual, expected);
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s1 = suite_create("memchr");
  TCase *tc1_1 = tcase_create("memchr");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, SEARCH_CHAR_IN_ONE_WORD);
  tcase_add_test(tc1_1, SEARCH_CHAR_IN_SENTENSE);
  tcase_add_test(tc1_1, SEARCH_CHAR_IN_DIFFICULT_SENTENSE);
  tcase_add_test(tc1_1, SEARCH_CHAR_IN_EMPTY_STRING);
  tcase_add_test(tc1_1, SEARCH_CHAR_IN_STRING_FROM_SPACES);
  tcase_add_test(tc1_1, SEARCH_MISSING_CHAR_IN_SENTENSE);
  return s1;
}