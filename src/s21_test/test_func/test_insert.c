#include "../s21_test.h"

START_TEST(s21_insert_test_1) {
  char *p_1 = "Aloha!";
  char *p_2 = ", kartoha";
  char *str = s21_insert(p_1, p_2, 5);
  if (str) {
    ck_assert_str_eq(str, "Aloha, kartoha!");
    free(str);
  }
}
END_TEST

START_TEST(s21_insert_test_2) {
  char *p_1 = "Aloha!";
  char *str = s21_insert(p_1, "", 20);
  // ck_assert(str == s21_NULL);
  ck_assert_ptr_eq(str, s21_NULL);
  // ck_assert_str_eq(str, s21_NULL);
  if (str) free(str);
}
END_TEST

START_TEST(s21_insert_test_3) {
  char *str = s21_insert("Hey!", "-way!!", 3);
  if (str) {
    ck_assert_str_eq(str, "Hey-way!!!");
    free(str);
  }
}
END_TEST

START_TEST(s21_insert_test_4) {
  char *str = s21_insert("Hey!", "-way!!", 15);
  // ck_assert(str == s21_NULL);
  ck_assert_ptr_eq(str, s21_NULL);
  // ck_assert_str_eq(str, s21_NULL);
  if (str) free(str);
}
END_TEST

START_TEST(s21_insert_test_5) {
  char *str = s21_insert("", "", 0);
  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }
}
END_TEST

Suite *suite_insert(void) {
  Suite *s1 = suite_create("Insert");
  TCase *tc1_1 = tcase_create("Insert");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_insert_test_1);
  tcase_add_test(tc1_1, s21_insert_test_2);
  tcase_add_test(tc1_1, s21_insert_test_3);
  tcase_add_test(tc1_1, s21_insert_test_4);
  tcase_add_test(tc1_1, s21_insert_test_5);

  return s1;
}