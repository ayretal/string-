#include "../s21_test.h"

START_TEST(s21_strrchr_test) {
  char strrchr_test1[] = "hello world";
  int strrchr_c1 = 'o';
  ck_assert_ptr_eq(s21_strrchr(strrchr_test1, strrchr_c1),
                   strrchr(strrchr_test1, strrchr_c1));

  char strrchr_test2[] = "repeat test case";
  int strrchr_c2 = 'z';
  ck_assert_ptr_null(s21_strrchr(strrchr_test2, strrchr_c2));

  char strrchr_test3[] = "look for the last occurrence";
  int strrchr_c3 = ' ';
  ck_assert_ptr_eq(s21_strrchr(strrchr_test3, strrchr_c3),
                   strrchr(strrchr_test3, strrchr_c3));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s1 = suite_create("strrchr");
  TCase *tc1_1 = tcase_create("strrchr");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_strrchr_test);
  return s1;
}