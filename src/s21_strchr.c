#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  // ищем символ c в строке str
  while (*str != '\0' && *str != c) {
    str++;
  }
  if (*str == c) {
    result = (char *)str;
  }

  return result;  // возвращаем NULL или указатель на символ
}