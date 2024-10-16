#include "../s21_test.h"

START_TEST(COPY_SMALL_IN_LARGE) {
  const char word[10] = "Hello";
  char simple_phrase[50] = "I think it must \n work";
  int small_size = 4;
  void *actual = s21_memcpy(simple_phrase, word, small_size);
  void *expected = memcpy(simple_phrase, word, small_size);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(COPY_EMPTY_IN_LARGE) {
  char simple_phrase[50] = "I think it must \n work";
  const char empty_string[50] = "";
  int small_size = 4;
  void *actual = s21_memcpy(simple_phrase, empty_string, small_size);
  void *expected = memcpy(simple_phrase, empty_string, small_size);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(COPY_SPACES_IN_LARGE) {
  char simple_phrase[50] = "I think it must \n work";
  const char space_instead_of_string[50] = "       ";
  int small_size = 4;
  void *actual = s21_memcpy(simple_phrase, space_instead_of_string, small_size);
  void *expected = memcpy(simple_phrase, space_instead_of_string, small_size);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s3 = suite_create("memcpy");
  TCase *tc3_1 = tcase_create("memcpy");
  suite_add_tcase(s3, tc3_1);
  tcase_add_test(tc3_1, COPY_SMALL_IN_LARGE);
  tcase_add_test(tc3_1, COPY_EMPTY_IN_LARGE);
  tcase_add_test(tc3_1, COPY_SPACES_IN_LARGE);
  return s3;
}