#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *temp_dest = (char *)dest;
  char *temp_src = (char *)src;
  for (int i = 0; i < (int)n; i++) {
    temp_dest[i] = temp_src[i];
  }
  return temp_dest;
}
