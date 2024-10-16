#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper_str = s21_NULL;
  if (str) upper_str = (char *)calloc(s21_strlen(str) + 1, sizeof(char));

  if (upper_str)
    for (char *upper_ptr = upper_str; *str; ++str, ++upper_ptr) {
      if (*str >= 97 && *str <= 122)
        *upper_ptr = *str - 32;
      else
        *upper_ptr = *str;
    }
  return upper_str;  // не забыть очистить память!!!
}