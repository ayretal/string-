#include "s21_strerror.h"

#include "s21_string.h"

char *s21_strerror(int errnum) {
  s21_size_t i = 0;
  for (; i <= S21_ERR_COUNT; ++i) {
    if (errnum == s21_error_list[i].s21_errnum) break;
  }
  return (char *)s21_error_list[i].s21_message;
}