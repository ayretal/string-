#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *temp_str = (char *)str;
  for (int i = 0; i < (int)n; i++) {
    temp_str[i] = c;
  }
  str = temp_str;
  return str;
}
