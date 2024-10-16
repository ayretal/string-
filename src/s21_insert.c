#include <stdlib.h>

#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  const char *s = src;

  if (s < d) {
    for (s21_size_t i = n; i > 0; --i) {
      d[i - 1] = s[i - 1];
    }
  } else {
    for (s21_size_t i = 0; i < n; ++i) {
      d[i] = s[i];
    }
  }

  return dest;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *n_src = s21_NULL;

  s21_size_t len_src = 0;
  s21_size_t len_str = 0;
  if (str && src) {
    len_src = s21_strlen(src);
    len_str = s21_strlen(str);
  }
  if (len_src > 0 && len_str > 0 && start_index <= len_src) {
    n_src = (char *)calloc(len_src + len_str + 1, sizeof(char));
    s21_strncpy(n_src, src, len_src);
    s21_memmove(n_src + start_index + len_str, n_src + start_index,
                len_src - start_index + 1);
    s21_memcpy(n_src + start_index, str, len_str);
  }
  return n_src;  // не забыть очистить память!!!
}