#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src &&
      trim_chars) {  // Проверяем, что ни один из указателей не является NULL
    // Устанавливаем начальный и конечный указатели на начало и конец исходной
    // строки
    char *start = (char *)src;
    char *end = (char *)src + s21_strlen(src) - 1;

    // Пропускаем символы из trim_chars в начале строки
    while (*start && s21_strchr(trim_chars, *start)) {
      start++;
    }

    // Пропускаем символы из trim_chars в конце строки
    while (end >= start && s21_strchr(trim_chars, *end)) {
      end--;
    }

    s21_size_t length = (s21_size_t)(end - start) + 1;
    result = (char *)malloc(length + 1);  // +1 для нулевого символа

    if (result) {
      s21_strncpy(result, start, length);
      result[length] = '\0';
    }
  }
  return result;  // Возвращаем результат
}
