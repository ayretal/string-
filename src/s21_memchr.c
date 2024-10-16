#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *temp_str = (char *)str;
  char *result = s21_NULL;

  for (int i = 0; i < (int)n; i++) {
    if (temp_str[i] == c) {
      result = temp_str + i;
      break;
    }
  }
  return result;
}