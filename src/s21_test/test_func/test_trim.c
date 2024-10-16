#include "../s21_test.h"

START_TEST(s21_trim_test) {
  char *trim_str;
  char *str_1 = " XOXOXO Merry christmas! Xoxoxo ";
  char *empty = "";

  trim_str = s21_trim(str_1, " Xr!");
  if (trim_str) {
    ck_assert_str_eq(trim_str, "OXOXO Merry christmas! Xoxoxo");
    free(trim_str);
  }

  trim_str = s21_trim(empty, s21_NULL);
  if (trim_str) {
    ck_assert_str_eq(trim_str, "");
    free(trim_str);
  }

  trim_str = s21_trim(empty, " \n\0");
  if (trim_str) {
    ck_assert_str_eq(trim_str, "");
    free(trim_str);
  }

  trim_str = s21_trim(s21_NULL, empty);
  ck_assert(trim_str == s21_NULL);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s1 = suite_create("Trim");
  TCase *tc1_1 = tcase_create("Trim");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_trim_test);

  return s1;
}