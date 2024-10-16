#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *str_one = (char *)str1;
  char *str_two = (char *)str2;
  int result = 0;
  for (int i = 0; i < (int)n; i++) {
    if (str_one[i] != str_two[i]) {
      result = str_one[i] - str_two[i];
      break;
    }
  }
  return result;
}