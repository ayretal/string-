#include "../s21_test.h"

char str[50];
char str_orig[50];

START_TEST(BASE_ONE) {
  char c = 'X';
  int n = 8;
  const char *form_str_2 = "Aloha, %4.*c";
  int actual = s21_sprintf(str, form_str_2, n, c);
  int expected = sprintf(str_orig, form_str_2, n, c);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}

END_TEST
START_TEST(BASE_TWO) {
  char c = 'X';
  char n = 'Y';
  const char *form_str_2 = "Aloha, %c %c";
  int actual = s21_sprintf(str, form_str_2, c, n);
  int expected = sprintf(str_orig, form_str_2, c, n);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(BASE_THREE) {
  const char *form_str_3 = "Aloha, %11s %11.10s";
  char *s1 = "people!";
  char *s2 = "Aloha people!";
  int actual = s21_sprintf(str, form_str_3, s1, s2);
  int expected = sprintf(str_orig, form_str_3, s1, s2);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_ONE) {
  double a_1 = 1;
  int actual = s21_sprintf(str, "%.f", a_1);
  int expected = sprintf(str_orig, "%.f", a_1);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_ONE_HASH) {
  double a_1 = 1;
  int actual = s21_sprintf(str, "%#.0f", a_1);
  int expected = sprintf(str_orig, "%#.0f", a_1);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_ONE_1) {
  double a_1 = 9.999;
  int actual = s21_sprintf(str, "%.2f", a_1);
  int expected = sprintf(str_orig, "%.2f", a_1);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_ONE_2) {
  double a_1 = 10.999;
  int actual = s21_sprintf(str, "%.2f", a_1);
  int expected = sprintf(str_orig, "%.2f", a_1);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_ONE_1L) {
  long double a_1 = 9.999;
  int actual = s21_sprintf(str, "%.2Lf", a_1);
  int expected = sprintf(str_orig, "%.2Lf", a_1);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_ONE_2L) {
  long double a_1 = 10.999;
  int actual = s21_sprintf(str, "%.2Lf", a_1);
  int expected = sprintf(str_orig, "%.2Lf", a_1);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_TWO) {
  double a_2 = 0;
  int actual = s21_sprintf(str, "%0+.10f", a_2);
  int expected = sprintf(str_orig, "%0+.10f", a_2);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_THREE) {
  double a_3 = 0.0000123;
  int actual = s21_sprintf(str, "%+-10.5f", a_3);
  int expected = sprintf(str_orig, "%+-10.5f", a_3);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_FOUR) {
  long double a_4 = -10.0000123;
  int actual = s21_sprintf(str, "%10.5Lf", a_4);
  int expected = sprintf(str_orig, "%10.5Lf", a_4);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_FIVE) {
  double a_5 = 12345.123456;
  int actual = s21_sprintf(str, "%.5f", a_5);
  int expected = sprintf(str_orig, "%.5f", a_5);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_SIX) {
  double a_6 = 345677823.0000123456789987654321;
  int actual = s21_sprintf(str, "%.20f", a_6);
  int expected = sprintf(str_orig, "%.20f", a_6);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_SEVEN) {
  double a_7 = 1.0 / 0.0;
  int actual = s21_sprintf(str, "%#5.0f", a_7);
  int expected = sprintf(str_orig, "%#5.0f", a_7);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(F_EIGHT) {
  long double a_8 = 0;
  int actual = s21_sprintf(str, "%#.0Lf", a_8);
  int expected = sprintf(str_orig, "%#.0Lf", a_8);
  ck_assert_int_eq(actual, expected);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(C_ONE) {
  char b = 'c';
  int actual = s21_sprintf(str, "%-5c", b);
  int expected = sprintf(str_orig, "%-5c", b);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(C_TWO) {
  char b = 'c';
  int actual = s21_sprintf(str, "%5c", b);
  int expected = sprintf(str_orig, "%5c", b);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(S_ONE) {
  char *b = "parallelepiped";
  int actual = s21_sprintf(str, "%-10.5s", b);
  int expected = sprintf(str_orig, "%-10.5s", b);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(S_TWO) {
  char *b = "parallelepiped";
  int actual = s21_sprintf(str, "%5.5s", b);
  int expected = sprintf(str_orig, "%5.5s", b);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_ONE) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%10.5u", x);
  int expected = sprintf(str_orig, "%10.5u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_TWO) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%5.5u", x);
  int expected = sprintf(str_orig, "%5.5u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_THREE) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%0u", x);
  int expected = sprintf(str_orig, "%0u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_FOUR) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%-u", x);
  int expected = sprintf(str_orig, "%-u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_FIVE) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%u", x);
  int expected = sprintf(str_orig, "%u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_SIX) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%7u", x);
  int expected = sprintf(str_orig, "%7u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_SEVEN) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%07u", x);
  int expected = sprintf(str_orig, "%07u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_EIGHT) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%-7u", x);
  int expected = sprintf(str_orig, "%-7u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_NINE) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%9u", x);
  int expected = sprintf(str_orig, "%9u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_TEN) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%.7u", x);
  int expected = sprintf(str_orig, "%.7u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_ELEVEN) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%-.7u", x);
  int expected = sprintf(str_orig, "%-.7u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_TWELVE) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%01u", x);
  int expected = sprintf(str_orig, "%01u", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_THIRTEEN) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%hu", (unsigned short)x);
  int expected = sprintf(str_orig, "%hu", (unsigned short)x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(U_FOURTEEN) {
  unsigned int x = 2024;
  int actual = s21_sprintf(str, "%lu", (unsigned long)x);
  int expected = sprintf(str_orig, "%lu", (unsigned long)x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_ONE) {
  int x = 1234;
  int actual = s21_sprintf(str, "%10.8d", x);
  int expected = sprintf(str_orig, "%10.8d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TWO) {
  int x = 1234;
  int actual = s21_sprintf(str, "%5.8d", x);
  int expected = sprintf(str_orig, "%5.8d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_THREE) {
  int x = 1234;
  int actual = s21_sprintf(str, "%0d", x);
  int expected = sprintf(str_orig, "%0d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_FOUR) {
  int x = 1234;
  int actual = s21_sprintf(str, "%-d", x);
  int expected = sprintf(str_orig, "%-d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_FIVE) {
  int x = 1234;
  int actual = s21_sprintf(str, "%d", x);
  int expected = sprintf(str_orig, "%d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_SIX) {
  int x = 1234;
  int actual = s21_sprintf(str, "%7d", x);
  int expected = sprintf(str_orig, "%7d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_SEVEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%07d", x);
  int expected = sprintf(str_orig, "%07d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_EIGHT) {
  int x = 1234;
  int actual = s21_sprintf(str, "%-7d", x);
  int expected = sprintf(str_orig, "%-7d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
/*
START_TEST(D_NINE) {
  int x = 1234;
  int actual = s21_sprintf(str, "%0.7d", x);
  int expected = sprintf(str_orig, "%0.7d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
*/
START_TEST(D_TEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%.7d", x);
  int expected = sprintf(str_orig, "%.7d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_ELEVEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%-.7d", x);
  int expected = sprintf(str_orig, "%-.7d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TWELVE) {
  int x = 1234;
  int actual = s21_sprintf(str, "%01d", x);
  int expected = sprintf(str_orig, "%01d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_THIRTEEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%hd", (short)x);
  int expected = sprintf(str_orig, "%hd", (short)x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_FOURTEEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%ld", (long)x);
  int expected = sprintf(str_orig, "%ld", (long)x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_FIFTEEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%+d", x);
  int expected = sprintf(str_orig, "%+d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_SIXTEEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%+5.5d", x);
  int expected = sprintf(str_orig, "%+5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_SEVENTEEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "%-5.5d", x);
  int expected = sprintf(str_orig, "%-5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_EIGHTEEN) {
  int x = 1234;
  int actual = s21_sprintf(str, "% 5.5d", x);
  int expected = sprintf(str_orig, "% 5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_ONE) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%10.5d", x);
  int expected = sprintf(str_orig, "%10.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_TWO) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%5.5d", x);
  int expected = sprintf(str_orig, "%5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_THREE) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%0d", x);
  int expected = sprintf(str_orig, "%0d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_FOUR) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%-d", x);
  int expected = sprintf(str_orig, "%-d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_FIVE) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%d", x);
  int expected = sprintf(str_orig, "%d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_SIX) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%3d", x);
  int expected = sprintf(str_orig, "%3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_SEVEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%03d", x);
  int expected = sprintf(str_orig, "%03d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_EIGHT) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%-3d", x);
  int expected = sprintf(str_orig, "%-3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
/*
START_TEST(D_T_NINE) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%0.3d", x);
  int expected = sprintf(str_orig, "%0.3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
*/
START_TEST(D_T_TEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%.3d", x);
  int expected = sprintf(str_orig, "%.3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_ELEVEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%-.3d", x);
  int expected = sprintf(str_orig, "%-.3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_TWELVE) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%01d", x);
  int expected = sprintf(str_orig, "%01d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_THIRTEEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%5.1d", x);
  int expected = sprintf(str_orig, "%5.1d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
/*
START_TEST(D_T_FOURTEEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%0.1d", x);
  int expected = sprintf(str_orig, "%0.1d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
*/
START_TEST(D_T_FIFTEEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%+d", x);
  int expected = sprintf(str_orig, "%+d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_SIXTEEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%+5.5d", x);
  int expected = sprintf(str_orig, "%+5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_SEVENTEEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "%-5.5d", x);
  int expected = sprintf(str_orig, "%-5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_T_EIGHTEEN) {
  int x = -12345678;
  int actual = s21_sprintf(str, "% 5.5d", x);
  int expected = sprintf(str_orig, "% 5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_ONE) {
  int x = 25;
  int actual = s21_sprintf(str, "%+5.5d", x);
  int expected = sprintf(str_orig, "%+5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_TWO) {
  int x = 25;
  int actual = s21_sprintf(str, "%5.5d", x);
  int expected = sprintf(str_orig, "%5.5d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_THREE) {
  int x = 25;
  int actual = s21_sprintf(str, "%0d", x);
  int expected = sprintf(str_orig, "%0d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_FOUR) {
  int x = 25;
  int actual = s21_sprintf(str, "%-d", x);
  int expected = sprintf(str_orig, "%-d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_FIVE) {
  int x = 25;
  int actual = s21_sprintf(str, "%d", x);
  int expected = sprintf(str_orig, "%d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_SIX) {
  int x = 25;
  int actual = s21_sprintf(str, "%3d", x);
  int expected = sprintf(str_orig, "%3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_SEVEN) {
  int x = 25;
  int actual = s21_sprintf(str, "%03d", x);
  int expected = sprintf(str_orig, "%03d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_EIGHT) {
  int x = 25;
  int actual = s21_sprintf(str, "%-3d", x);
  int expected = sprintf(str_orig, "%-3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_NINE) {
  int x = 25;
  int actual = s21_sprintf(str, "%-5.3d", -x);
  int expected = sprintf(str_orig, "%-5.3d", -x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_TEN) {
  int x = 25;
  int actual = s21_sprintf(str, "%+-d", x);
  int expected = sprintf(str_orig, "%+-d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(D_TH_ELEVEN) {
  int x = 25;
  int actual = s21_sprintf(str, "%+-5.3d", x);
  int expected = sprintf(str_orig, "%+-5.3d", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_ONE) {
  int x = 234;
  int actual = s21_sprintf(str, "%10.5i", x);
  int expected = sprintf(str_orig, "%10.5i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_TWO) {
  int x = 234;
  int actual = s21_sprintf(str, "%5.5i", x);
  int expected = sprintf(str_orig, "%5.5i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_THREE) {
  int x = 234;
  int actual = s21_sprintf(str, "%0i", x);
  int expected = sprintf(str_orig, "%0i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_FOUR) {
  int x = 234;
  int actual = s21_sprintf(str, "%-i", x);
  int expected = sprintf(str_orig, "%-i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_FIVE) {
  int x = 234;
  int actual = s21_sprintf(str, "%i", x);
  int expected = sprintf(str_orig, "%i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_SIX) {
  int x = 234;
  int actual = s21_sprintf(str, "%7i", x);
  int expected = sprintf(str_orig, "%7i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_SEVEN) {
  int x = 234;
  int actual = s21_sprintf(str, "%07i", x);
  int expected = sprintf(str_orig, "%07i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_EIGHT) {
  int x = 234;
  int actual = s21_sprintf(str, "%-7i", x);
  int expected = sprintf(str_orig, "%-7i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_NINE) {
  int x = 234;
  int actual = s21_sprintf(str, "%+6.3i", x);
  int expected = sprintf(str_orig, "%+6.3i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_TEN) {
  int x = 234;
  int actual = s21_sprintf(str, "%.7i", x);
  int expected = sprintf(str_orig, "%.7i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_ELEVEN) {
  int x = 234;
  int actual = s21_sprintf(str, "%-.7i", x);
  int expected = sprintf(str_orig, "%-.7i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_TWELVE) {
  int x = 234;
  int actual = s21_sprintf(str, "%+-i", x);
  int expected = sprintf(str_orig, "%+-i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_ONE) {
  int x = -354;
  int actual = s21_sprintf(str, "%10.5i", x);
  int expected = sprintf(str_orig, "%10.5i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_ONE_1) {
  int x = 354;
  int actual = s21_sprintf(str, "%+-10i", x);
  int expected = sprintf(str_orig, "%+-10i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_TWO) {
  int x = -354;
  int actual = s21_sprintf(str, "%5.5i", x);
  int expected = sprintf(str_orig, "%5.5i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_THREE) {
  int x = -354;
  int actual = s21_sprintf(str, "%0i", x);
  int expected = sprintf(str_orig, "%0i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_FOUR) {
  int x = -354;
  int actual = s21_sprintf(str, "%-i", x);
  int expected = sprintf(str_orig, "%-i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_FIVE) {
  int x = -354;
  int actual = s21_sprintf(str, "%i", x);
  int expected = sprintf(str_orig, "%i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_SIX) {
  int x = -354;
  int actual = s21_sprintf(str, "%3i", x);
  int expected = sprintf(str_orig, "%3i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_SEVEN) {
  int x = -354;
  int actual = s21_sprintf(str, "%03i", x);
  int expected = sprintf(str_orig, "%03i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_EIGHT) {
  int x = -354;
  int actual = s21_sprintf(str, "%-3i", x);
  int expected = sprintf(str_orig, "%-3i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
/*
START_TEST(I_2_NINE) {
  int x = -354;
  int actual = s21_sprintf(str, "%0.3i", x);
  int expected = sprintf(str_orig, "%0.3i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST
*/
START_TEST(I_2_TEN) {
  int x = -354;
  int actual = s21_sprintf(str, "%.3i", x);
  int expected = sprintf(str_orig, "%.3i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(I_2_ELEVEN) {
  int x = -354;
  int actual = s21_sprintf(str, "%-.3i", x);
  int expected = sprintf(str_orig, "%-.3i", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_E) {
  double x = 42;
  int actual = s21_sprintf(str, "%e", x);
  int expected = sprintf(str_orig, "%e", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_EL) {
  long double x = 123.4;
  int actual = s21_sprintf(str, "%+015.2Le", x);
  int expected = sprintf(str_orig, "%+015.2Le", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_E) {
  double x = 42;
  int actual = s21_sprintf(str, "%E", x);
  int expected = sprintf(str_orig, "%E", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_EL) {
  long double x = 4123.42;
  int actual = s21_sprintf(str, "%LE", x);
  int expected = sprintf(str_orig, "%LE", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_G) {
  double x = 42;
  int actual = s21_sprintf(str, "%g", x);
  int expected = sprintf(str_orig, "%g", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_GE) {
  long double x = 0.9;
  int actual = s21_sprintf(str, "%Lg", x);
  int expected = sprintf(str_orig, "%Lg", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_GE_2) {
  double x = 0.9;
  int actual = s21_sprintf(str, "%g", x);
  int expected = sprintf(str_orig, "%g", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_GE_3) {
  double x = -123000000000.0;
  int actual = s21_sprintf(str, "%g", x);
  int expected = sprintf(str_orig, "%g", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_LG) {
  long double x = 42;
  int actual = s21_sprintf(str, "%Lg", x);
  int expected = sprintf(str_orig, "%Lg", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_LG1) {
  long double x = -123000000000.0;
  int actual = s21_sprintf(str, "%Lg", x);
  int expected = sprintf(str_orig, "%Lg", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_G) {
  double x = 42;
  int actual = s21_sprintf(str, "%G", x);
  int expected = sprintf(str_orig, "%G", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_GE) {
  long double x = 0.9;
  int actual = s21_sprintf(str, "%LG", x);
  int expected = sprintf(str_orig, "%LG", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_GE_2) {
  double x = 0.9;
  int actual = s21_sprintf(str, "%G", x);
  int expected = sprintf(str_orig, "%G", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_GE_3) {
  double x = -123000000000.0;
  int actual = s21_sprintf(str, "%G", x);
  int expected = sprintf(str_orig, "%G", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_LG1) {
  long double x = -123000000000.0;
  int actual = s21_sprintf(str, "%LG", x);
  int expected = sprintf(str_orig, "%LG", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_LG) {
  long double x = 42;
  int actual = s21_sprintf(str, "%LG", x);
  int expected = sprintf(str_orig, "%LG", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(O) {
  int x = 42;
  int actual = s21_sprintf(str, "%o", x);
  int expected = sprintf(str_orig, "%o", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(HASH_O) {
  int x = 1234;
  int actual = s21_sprintf(str, "%#-6.7o", x);
  int expected = sprintf(str_orig, "%#-6.7o", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(HASH_O1) {
  int x = 1234;
  int actual = s21_sprintf(str, "%#-6.2o", x);
  int expected = sprintf(str_orig, "%#-6.2o", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_X) {
  int x = 42;
  int actual = s21_sprintf(str, "%x", x);
  int expected = sprintf(str_orig, "%x", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_X_1) {
  int x = 123;
  int actual = s21_sprintf(str, "%#x", x);
  int expected = sprintf(str_orig, "%#x", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_X_2) {
  int x = 123;
  int actual = s21_sprintf(str, "%#10x", x);
  int expected = sprintf(str_orig, "%#10x", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_X) {
  int x = 42;
  int actual = s21_sprintf(str, "%X", x);
  int expected = sprintf(str_orig, "%X", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_X_1) {
  int x = 42;
  int actual = s21_sprintf(str, "%#X", x);
  int expected = sprintf(str_orig, "%#X", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_X_2) {
  int x = 42;
  int actual = s21_sprintf(str, "%#10X", x);
  int expected = sprintf(str_orig, "%#10X", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(P) {
  char *arr = "Hello";
  int actual = s21_sprintf(str, "%p", arr);
  int expected = sprintf(str_orig, "%p", arr);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(P_30) {
  char *arr = "Hello";
  int actual = s21_sprintf(str, "%30p", arr);
  int expected = sprintf(str_orig, "%30p", arr);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(H) {
  short x = 42;
  int actual = s21_sprintf(str, "%hd", x);
  int expected = sprintf(str_orig, "%hd", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(SMALL_L) {
  long x = 42;
  int actual = s21_sprintf(str, "%ld", x);
  int expected = sprintf(str_orig, "%ld", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(BIG_L) {
  long double x = 42;
  int actual = s21_sprintf(str, "%Lf", x);
  int expected = sprintf(str_orig, "%Lf", x);
  ck_assert_str_eq(str, str_orig);
  ck_assert_int_eq(actual, expected);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s_sprintf = suite_create("sprintf");
  TCase *tc1_1 = tcase_create("base");
  TCase *tc1_2 = tcase_create("f");
  TCase *tc1_3 = tcase_create("c");
  TCase *tc1_4 = tcase_create("s");
  TCase *tc1_5 = tcase_create("u");
  TCase *tc1_6 = tcase_create("d");
  TCase *tc1_7 = tcase_create("d_2");
  TCase *tc1_8 = tcase_create("d_3");
  TCase *tc1_9 = tcase_create("i");
  TCase *tc1_10 = tcase_create("i_2");

  TCase *tc1_11 = tcase_create("e");
  TCase *tc1_12 = tcase_create("E");
  TCase *tc1_13 = tcase_create("g");
  TCase *tc1_14 = tcase_create("G");
  TCase *tc1_15 = tcase_create("o");
  TCase *tc1_16 = tcase_create("x");
  TCase *tc1_17 = tcase_create("X");
  TCase *tc1_18 = tcase_create("p");
  // TCase *tc1_19 = tcase_create("n");
  TCase *tc1_20 = tcase_create("h");
  TCase *tc1_21 = tcase_create("l");
  TCase *tc1_22 = tcase_create("L");

  suite_add_tcase(s_sprintf, tc1_1);
  tcase_add_test(tc1_1, BASE_ONE);
  tcase_add_test(tc1_1, BASE_TWO);
  tcase_add_test(tc1_1, BASE_THREE);
  suite_add_tcase(s_sprintf, tc1_2);
  tcase_add_test(tc1_2, F_ONE);
  tcase_add_test(tc1_2, F_ONE_HASH);
  tcase_add_test(tc1_2, F_ONE_1);
  tcase_add_test(tc1_2, F_ONE_2);
  tcase_add_test(tc1_2, F_ONE_1L);
  tcase_add_test(tc1_2, F_ONE_2L);
  tcase_add_test(tc1_2, F_TWO);
  tcase_add_test(tc1_2, F_THREE);
  tcase_add_test(tc1_2, F_FOUR);
  tcase_add_test(tc1_2, F_FIVE);
  tcase_add_test(tc1_2, F_SIX);
  tcase_add_test(tc1_2, F_SEVEN);
  tcase_add_test(tc1_2, F_EIGHT);
  suite_add_tcase(s_sprintf, tc1_3);
  tcase_add_test(tc1_3, C_ONE);
  tcase_add_test(tc1_3, C_TWO);
  suite_add_tcase(s_sprintf, tc1_4);
  tcase_add_test(tc1_4, S_ONE);
  tcase_add_test(tc1_4, S_TWO);
  suite_add_tcase(s_sprintf, tc1_5);
  tcase_add_test(tc1_5, U_ONE);
  tcase_add_test(tc1_5, U_TWO);
  tcase_add_test(tc1_5, U_THREE);
  tcase_add_test(tc1_5, U_FOUR);
  tcase_add_test(tc1_5, U_FIVE);
  tcase_add_test(tc1_5, U_SIX);
  tcase_add_test(tc1_5, U_SEVEN);
  tcase_add_test(tc1_5, U_EIGHT);
  tcase_add_test(tc1_5, U_NINE);
  tcase_add_test(tc1_5, U_TEN);
  tcase_add_test(tc1_5, U_ELEVEN);
  tcase_add_test(tc1_5, U_TWELVE);
  tcase_add_test(tc1_5, U_THIRTEEN);
  tcase_add_test(tc1_5, U_FOURTEEN);
  suite_add_tcase(s_sprintf, tc1_6);
  tcase_add_test(tc1_6, D_ONE);
  tcase_add_test(tc1_6, D_TWO);
  tcase_add_test(tc1_6, D_THREE);
  tcase_add_test(tc1_6, D_FOUR);
  tcase_add_test(tc1_6, D_FIVE);
  tcase_add_test(tc1_6, D_SIX);
  tcase_add_test(tc1_6, D_SEVEN);
  tcase_add_test(tc1_6, D_EIGHT);
  // tcase_add_test(tc1_6, D_NINE);
  tcase_add_test(tc1_6, D_TEN);
  tcase_add_test(tc1_6, D_ELEVEN);
  tcase_add_test(tc1_6, D_TWELVE);
  tcase_add_test(tc1_6, D_THIRTEEN);
  tcase_add_test(tc1_6, D_FOURTEEN);
  tcase_add_test(tc1_6, D_FIFTEEN);
  tcase_add_test(tc1_6, D_SIXTEEN);
  tcase_add_test(tc1_6, D_SEVENTEEN);
  tcase_add_test(tc1_6, D_EIGHTEEN);
  suite_add_tcase(s_sprintf, tc1_7);
  tcase_add_test(tc1_7, D_T_ONE);
  tcase_add_test(tc1_7, D_T_TWO);
  tcase_add_test(tc1_7, D_T_THREE);
  tcase_add_test(tc1_7, D_T_FOUR);
  tcase_add_test(tc1_7, D_T_FIVE);
  tcase_add_test(tc1_7, D_T_SIX);
  tcase_add_test(tc1_7, D_T_SEVEN);
  tcase_add_test(tc1_7, D_T_EIGHT);
  // tcase_add_test(tc1_7, D_T_NINE);
  tcase_add_test(tc1_7, D_T_TEN);
  tcase_add_test(tc1_7, D_T_ELEVEN);
  tcase_add_test(tc1_7, D_T_TWELVE);
  tcase_add_test(tc1_7, D_T_THIRTEEN);
  // tcase_add_test(tc1_7, D_T_FOURTEEN);
  tcase_add_test(tc1_7, D_T_FIFTEEN);
  tcase_add_test(tc1_7, D_T_SIXTEEN);
  tcase_add_test(tc1_7, D_T_SEVENTEEN);
  tcase_add_test(tc1_7, D_T_EIGHTEEN);
  suite_add_tcase(s_sprintf, tc1_8);
  tcase_add_test(tc1_8, D_TH_ONE);
  tcase_add_test(tc1_8, D_TH_TWO);
  tcase_add_test(tc1_8, D_TH_THREE);
  tcase_add_test(tc1_8, D_TH_FOUR);
  tcase_add_test(tc1_8, D_TH_FIVE);
  tcase_add_test(tc1_8, D_TH_SIX);
  tcase_add_test(tc1_8, D_TH_SEVEN);
  tcase_add_test(tc1_8, D_TH_EIGHT);
  tcase_add_test(tc1_8, D_TH_NINE);
  tcase_add_test(tc1_8, D_TH_TEN);
  tcase_add_test(tc1_8, D_TH_ELEVEN);
  suite_add_tcase(s_sprintf, tc1_9);
  tcase_add_test(tc1_9, I_ONE);
  tcase_add_test(tc1_9, I_TWO);
  tcase_add_test(tc1_9, I_THREE);
  tcase_add_test(tc1_9, I_FOUR);
  tcase_add_test(tc1_9, I_FIVE);
  tcase_add_test(tc1_9, I_SIX);
  tcase_add_test(tc1_9, I_SEVEN);
  tcase_add_test(tc1_9, I_EIGHT);
  tcase_add_test(tc1_9, I_NINE);
  tcase_add_test(tc1_9, I_TEN);
  tcase_add_test(tc1_9, I_ELEVEN);
  tcase_add_test(tc1_9, I_TWELVE);
  suite_add_tcase(s_sprintf, tc1_10);
  tcase_add_test(tc1_10, I_2_ONE);
  tcase_add_test(tc1_10, I_2_ONE_1);
  tcase_add_test(tc1_10, I_2_TWO);
  tcase_add_test(tc1_10, I_2_THREE);
  tcase_add_test(tc1_10, I_2_FOUR);
  tcase_add_test(tc1_10, I_2_FIVE);
  tcase_add_test(tc1_10, I_2_SIX);
  tcase_add_test(tc1_10, I_2_SEVEN);
  tcase_add_test(tc1_10, I_2_EIGHT);
  // tcase_add_test(tc1_10, I_2_NINE);
  tcase_add_test(tc1_10, I_2_TEN);
  tcase_add_test(tc1_10, I_2_ELEVEN);
  suite_add_tcase(s_sprintf, tc1_11);
  tcase_add_test(tc1_11, SMALL_E);
  tcase_add_test(tc1_11, SMALL_EL);
  suite_add_tcase(s_sprintf, tc1_12);
  tcase_add_test(tc1_12, BIG_E);
  tcase_add_test(tc1_12, BIG_EL);
  suite_add_tcase(s_sprintf, tc1_13);
  tcase_add_test(tc1_13, SMALL_G);
  tcase_add_test(tc1_13, SMALL_GE);
  tcase_add_test(tc1_13, SMALL_GE_2);
  tcase_add_test(tc1_13, SMALL_GE_3);
  tcase_add_test(tc1_13, SMALL_LG);
  tcase_add_test(tc1_13, SMALL_LG1);
  suite_add_tcase(s_sprintf, tc1_14);
  tcase_add_test(tc1_14, BIG_G);
  tcase_add_test(tc1_14, BIG_GE);
  tcase_add_test(tc1_14, BIG_GE_2);
  tcase_add_test(tc1_14, BIG_GE_3);
  tcase_add_test(tc1_14, BIG_LG);
  tcase_add_test(tc1_14, BIG_LG1);
  suite_add_tcase(s_sprintf, tc1_15);
  tcase_add_test(tc1_15, O);
  tcase_add_test(tc1_15, HASH_O);
  tcase_add_test(tc1_15, HASH_O1);
  suite_add_tcase(s_sprintf, tc1_16);
  tcase_add_test(tc1_16, SMALL_X);
  tcase_add_test(tc1_16, SMALL_X_1);
  tcase_add_test(tc1_16, SMALL_X_2);
  suite_add_tcase(s_sprintf, tc1_17);
  tcase_add_test(tc1_17, BIG_X);
  tcase_add_test(tc1_17, BIG_X_1);
  tcase_add_test(tc1_17, BIG_X_2);
  suite_add_tcase(s_sprintf, tc1_18);
  tcase_add_test(tc1_18, P);
  tcase_add_test(tc1_18, P_30);
  // suite_add_tcase(s_sprintf, tc1_19);
  // tcase_add_test(tc1_19, N);
  suite_add_tcase(s_sprintf, tc1_20);
  tcase_add_test(tc1_20, H);
  suite_add_tcase(s_sprintf, tc1_21);
  tcase_add_test(tc1_21, SMALL_L);
  suite_add_tcase(s_sprintf, tc1_22);
  tcase_add_test(tc1_22, BIG_L);
  return s_sprintf;
}