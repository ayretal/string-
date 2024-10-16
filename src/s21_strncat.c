#include "s21_string.h"
// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *res = dest;  // сохраняем начальную позицию dest
  // находим конец dest
  while (*dest != '\0') {
    dest++;
  }

  // копируем не более n символов из src в конец dest
  while (*src != '\0' && n > 0) {
    *dest = *src;
    dest++;
    src++;
    n--;
  }

  *dest = '\0';  // добавляем завершающий нуль

  return res;  // возвращаем указатель на начало объединенной строки
}