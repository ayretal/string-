#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last = s21_NULL;
  char *start = s21_NULL;

  if (str != s21_NULL) {
    last = str;
  }

  // Если есть строка для обработки
  if (last != s21_NULL && *last != '\0') {
    // Пропускаем начальные разделители
    while (*last && s21_strchr(delim, *last)) last++;

    // Если не достигнут конец строки
    if (*last) {
      start = last;

      // Ищем следующий разделитель после начала токена
      while (*last && !s21_strchr(delim, *last)) last++;

      // Если найден разделитель, закрываем токен и готовим к следующему
      // вызову
      if (*last) {
        *last = '\0';
        last++;
      }
    }
  }

  // Возвращаем токен (или NULL, если токены закончились)
  return start;
}
