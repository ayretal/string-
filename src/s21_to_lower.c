#include <stdlib.h>

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *lower_str = s21_NULL;
  if (str) lower_str = (char *)calloc(s21_strlen(str) + 1, sizeof(char));

  if (lower_str)
    for (char *lower_ptr = lower_str; *str; ++str, ++lower_ptr) {
      if (*str >= 65 && *str <= 90)
        *lower_ptr = *str + 32;
      else
        *lower_ptr = *str;
    }
  return lower_str;  // не забыть очистить память!!!
}