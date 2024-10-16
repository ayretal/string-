#include "../s21_test.h"

START_TEST(COPY_CHAR_IN_SENTENSE) {
  char simple_phrase[] = "I think it must \n work";
  char ch = 'o';
  int small_size = 4;
  void *actual = s21_memset(simple_phrase, ch, small_size);
  void *expected = memset(simple_phrase, ch, small_size);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(COPY_SPACE_IN_SENTENSE) {
  char simple_phrase[] = "I think it must \n work";
  char space = ' ';
  int small_size = 4;
  void *actual = s21_memset(simple_phrase, space, small_size);
  void *expected = memset(simple_phrase, space, small_size);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

START_TEST(COPY_EOF_IN_SENTENSE) {
  char simple_phrase[] = "I think it must \n work";
  char end_ch = '\0';
  int small_size = 4;
  void *actual = s21_memset(simple_phrase, end_ch, small_size);
  void *expected = memset(simple_phrase, end_ch, small_size);
  ck_assert_str_eq((char *)actual, (char *)expected);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s4 = suite_create("memset");
  TCase *tc4_1 = tcase_create("memset");
  suite_add_tcase(s4, tc4_1);
  tcase_add_test(tc4_1, COPY_CHAR_IN_SENTENSE);
  tcase_add_test(tc4_1, COPY_SPACE_IN_SENTENSE);
  tcase_add_test(tc4_1, COPY_EOF_IN_SENTENSE);
  return s4;
}
