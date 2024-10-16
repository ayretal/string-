#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int flag = 0;
  s21_size_t i = 0;
  for (i = 0; (i < s21_strlen(haystack)) && (flag == 0); i++) {
    flag = 1;
    for (s21_size_t j = 0; (j < s21_strlen(needle)) && flag; j++) {
      if (haystack[i + j] != needle[j]) flag = 0;
    }
  }
  return flag ? (char *)&haystack[i - 1] : s21_NULL;
}