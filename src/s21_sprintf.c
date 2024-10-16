#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

#include "s21_string.h"

#define FLAG_MINUS 1        // 00001
#define FLAG_PLUS 2         // 00010
#define FLAG_SPACE 4        // 00100
#define FLAG_HASH 8         // 01000
#define FLAG_ZERO 16        // 10000
#define FLEN_h 32           // 00100000
#define FLEN_l 64           // 01000000
#define FLEN_L 128          // 10000000
#define FLAG_PRECISION 256  // 100000000

// структура для формата вывода текущего поля
struct print_options {
  unsigned int flags;  // также содержит модификаторы длины
  unsigned int width;      // ширина поля
  unsigned int precision;  // точность вывода
  char field_type;         // тип поля тоже понадобился
};

s21_size_t parse_flags(const char *format, unsigned int *flags);
s21_size_t parse_num(const char *format, unsigned int *num);
s21_size_t parse_length(const char *format, unsigned int *flags);
s21_size_t sprint_char(char *str, const char *c,
                       struct print_options *current_options);
s21_size_t sprint_string(char *str, char *s,
                         struct print_options *current_options);
void flip_string(char *s);
int int2str(int_fast64_t in, char *int_str, int base);
s21_size_t sprint_int(char *str, int_fast64_t *in,
                      struct print_options *current_options);
int uint2str(uint_fast64_t uin, char *uint_str, int base);
s21_size_t sprint_uint(char *str, uint_fast64_t *uin,
                       struct print_options *current_options);
s21_size_t df2str(double *df, char *df_str,
                  struct print_options *current_options);
s21_size_t sprint_double(char *str, double *df,
                         struct print_options *current_options);
int len_whole(int_fast64_t n, int base);
s21_size_t lf2str(long double *lf, char *lf_str,
                  struct print_options *current_options);
s21_size_t sprint_ldouble(char *str, long double *lf,
                          struct print_options *current_options);
int nan2str(char *str, int *negative, const int *nan,
            struct print_options *current_options);
s21_size_t parse_type(const char *format, struct print_options *current_options,
                      va_list *param, char *str, s21_size_t *fs_len);
s21_size_t parse_format(const char *format,
                        struct print_options *current_options, va_list *param);

// парсит флаги формата для вывода
// возвращает количество символов флагов
// состояние флагов записывает в flags
// начальные нули width будут прочитаны как флаги в этом парсере
// это не ошибка, они все равно не имеют никакого значения для ширины
s21_size_t parse_flags(const char *format, unsigned int *flags) {
  s21_size_t len = 0;
  int try_next = 1;
  while (try_next) {
    switch (*(format + len++)) {  // одновременно указатель на следующий символ
      case '-':
        *flags |= FLAG_MINUS;
        break;
      case '+':
        *flags |= FLAG_PLUS;
        break;
      case ' ':
        *flags |= FLAG_SPACE;
        break;
      case '#':
        *flags |= FLAG_HASH;
        break;
      case '0':
        *flags |= FLAG_ZERO;
        break;
      default:
        try_next = 0;  // следующий не проверяем
        len--;  // текущий символ - неподходящий или поле закончилось, вернемся
        break;
    }
  }
  return len;
}

// парсит цифры ширины поля или точности для вывода
// возвращает количество учтенных символов
// прочитанное числовое значение записывает в num
s21_size_t parse_num(const char *format, unsigned int *num) {
  s21_size_t len = 0;
  int try_next = 1;
  while (try_next) {
    *num *= 10;  // увеличим разряд и посмотрим, что там за символ
    switch (*(format + len++)) {  // одновременно указатель на следующий символ
      case '0':
        break;
      case '1':
        *num += 1;
        break;
      case '2':
        *num += 2;
        break;
      case '3':
        *num += 3;
        break;
      case '4':
        *num += 4;
        break;
      case '5':
        *num += 5;
        break;
      case '6':
        *num += 6;
        break;
      case '7':
        *num += 7;
        break;
      case '8':
        *num += 8;
        break;
      case '9':
        *num += 9;
        break;
      default:
        try_next = 0;  // следующий не проверяем
        len--;  // текущий символ - не цифра или поле закончилось, вернемся
        *num /= 10;  // разряд был лишним, уберем
        break;
    }
  }
  return len;
}

// парсит модификатор (только один) длины для вывода
// возвращает 1 если модификатора прочитан, 0 если нет
// состояние записывает в flags
s21_size_t parse_length(const char *format, unsigned int *flags) {
  s21_size_t len = 0;
  switch (*(format + len++)) {  // одновременно указатель на следующий символ
    case 'h':
      *flags |= FLEN_h;
      break;
    case 'l':
      *flags |= FLEN_l;
      break;
    case 'L':
      *flags |= FLEN_L;
      break;
    default:
      len--;  // текущий символ - неподходящий или поле закончилось, вернемся
      break;
  }
  return len;
}

// печатает символ с в строку str в соответствии со значениями флагов
// возвращает количество записанных в строку str символов
s21_size_t sprint_char(char *str, const char *c,
                       struct print_options *current_options) {
  s21_size_t len = 0;
  // печатаем пробелы до или после символа в зависимости от выравнивания
  // если ширина меньше одного символа, игнорируем ее
  if (!(current_options->flags & FLAG_MINUS) && current_options->width > 1)
    while (--(current_options->width)) {
      *str++ = ' ';
      len++;
    }
  *str = *c;  // непосредственно запись символа в строку
  if ((current_options->flags & FLAG_MINUS) && current_options->width > 1)
    while (--(current_options->width)) {
      *(++str) = ' ';
      len++;
    }
  return ++len;
}

// печатает строку s в строку str в соответствии со значениями флагов
// возвращает количество записанных в строку str символов
s21_size_t sprint_string(char *str, char *s,
                         struct print_options *current_options) {
  int delta = 0;
  s21_size_t len = s21_strlen(s);
  if (current_options->flags & FLAG_PRECISION &&
      current_options->precision < len &&
      !(current_options->field_type == 'f' ||
        current_options->field_type == 'F'))
    len = current_options->precision;
  if (current_options->width > len) delta = current_options->width - len;
  // пробелы в начале до заданной ширины
  if (!(current_options->flags & FLAG_MINUS) && delta > 0)
    while (delta--) {
      *str++ = ' ';
      len++;
    }
  // печатаем не больше заданной точности если есть флаг
  if (current_options->flags & FLAG_PRECISION) {
    while (*s && current_options->precision > 0) {
      *str++ = *s++;
      current_options->precision--;
    }
  } else {  // или всю строку
    while (*s) *str++ = *s++;
  }
  if (current_options->field_type == 'f' || current_options->field_type == 'F')
    while (*s) *str++ = *s++;
  //  пробелы в конце до заданной ширины
  if ((current_options->flags & FLAG_MINUS) && delta)
    while (delta--) {
      *str++ = ' ';
      len++;
    }
  return len;
}

// возвращает строку записанную в обратном порядке символов
void flip_string(char *s) {
  int i = 0;
  int j = s21_strlen(s) - 1;  // индекс последнего на единицу меньше длины
  for (; i < j; i++, j--) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// записывает целое число in в строку res в системе base (по hex)
// возвращает количество записанных в строку res символов
int int2str(int_fast64_t in, char *int_str, int base) {
  int len = 0;
  int negative = in < 0 ? 1 : 0;  // для минуса, если отрицательное число
  if (negative) in = -in;
  do {
    int digit = in % base;
    if (digit < 10) int_str[len++] = '0' + digit;
    // else  // если шестнадцатиричная система записи, выводим букву
    //  int_str[len++] = 'A' + digit - 10;
  } while ((in /= base) > 0);
  if (negative) int_str[len++] = '-';
  int_str[len] = '\0';
  flip_string(int_str);
  return len;
}

// печатает целое число in в строку str в соответствии с флагами
// возвращает количество записанных в строку str символов
s21_size_t sprint_int(char *str, int_fast64_t *in,
                      struct print_options *current_options) {
  // обрабатываем в соответствии с заданной длиной
  if (current_options->flags & FLEN_h)
    *in = (int16_t)*in;
  else if (current_options->flags & FLEN_l ||
           current_options->field_type == 'f' ||
           current_options->field_type == 'F')
    ;  // 64 уже по умолчанию задана
  else
    *in = (int32_t)*in;  // если никакого флага, то стандартный
  // тут десятичная система считсления числа
  int base = 10;
  char int_str[64] = {0};  // буфер с запасом для записи числа в строку
  s21_size_t len = int2str(*in, int_str, base);
  int delta = 0;
  if (*in < 0) current_options->precision++;  // дла правильного учета минуса
  // точность дополняет нулями число спереди
  if (current_options->precision > len) {
    delta = current_options->precision - len;  // разница
    len = current_options->precision;  // бОльшая точность - новая длина
    current_options->precision = delta;  // для дополнения нулями
    delta = 0;  // для дальнейшего использования переменной
  } else  // только если число короче точности
    current_options->precision = 0;

  if (current_options->width > len) delta = current_options->width - len;
  if (current_options->flags & FLAG_PLUS) delta--;

  char c = ' ';  // пробел или ноль, в зависимости от флага
  if (current_options->flags & FLAG_ZERO &&
      (!(current_options->flags & FLAG_PRECISION) ||
       (current_options->field_type == 'f') ||
       (current_options->field_type == 'F')))
    c = '0';
  int i = 0;
  if (*in < 0 && c == '0' &&
      ((current_options->flags & FLAG_PRECISION) || delta)) {
    *str++ = int_str[i++];  // минус печатаем перед заполнением
    delta--;
  } else if (current_options->flags & FLAG_PLUS &&
             current_options->flags & FLAG_ZERO &&
             !current_options->precision) {
    if (current_options->flags & FLAG_SPACE)
      *str++ = ' ';  // пробел вместо знака, если указан флаг
    else
      *str++ = '+';  // или плюс, если указан флаг
    len++;
    delta--;
  }
  //  символы в начале до заданной ширины
  if (!(current_options->flags & FLAG_MINUS) && delta > 0)
    while (delta--) {
      *str++ = c;
      len++;
    }
  if (*in >= 0 && current_options->flags & FLAG_PLUS && c == ' ') {
    if (current_options->flags & FLAG_SPACE)
      *str++ = ' ';  // пробел, если указан флаг
    else
      *str++ = '+';  // плюс, если указан флаг и нет заполнения нулями
    len++;
  }
  if (*in > 0 && current_options->flags & FLAG_SPACE && c == ' ') {
    *str++ = ' ';  // пробел вместо знака, если указан флаг
    len++;
    delta--;
  }
  if (*in < 0 && c == ' ' && current_options->precision) {
    *str++ = int_str[i++];  // минус печатаем перед заполнением
  }
  while (current_options->precision--) {
    *str++ = '0';  // нули впереди до нужной точности
  }
  for (; int_str[i];) *str++ = int_str[i++];  // непосредственно вывод числа
  //  пробелы в конце до заданной ширины
  //  нули нельзя, т.к. это изменит целое число
  if ((current_options->flags & FLAG_MINUS) && delta > 0)
    while (delta--) {
      *str++ = ' ';
      len++;
    }
  return len;
}

// записывает целое число uin в строку res в системе base (по hex)
// возвращает количество записанных в строку res символов
int uint2str(uint_fast64_t uin, char *uint_str, int base) {
  int len = 0;
  do {
    int digit = uin % base;
    if (digit < 10)
      uint_str[len++] = '0' + digit;
    else  // если шестнадцатиричная система записи, выводим букву
      uint_str[len++] = 'a' + digit - 10;
  } while ((uin /= base) > 0);
  uint_str[len] = '\0';
  flip_string(uint_str);
  return len;
}

// печатает целое число uin в строку str в соответствии с флагами
// возвращает количество записанных в строку str символов
s21_size_t sprint_uint(char *str, uint_fast64_t *uin,
                       struct print_options *current_options) {
  // обрабатываем в соответствии с заданной длиной
  if (!(current_options->field_type == 'p')) {
    if (current_options->flags & FLEN_h)
      *uin = (uint16_t)*uin;
    else if (current_options->flags & FLEN_l)
      ;  // 64 уже по умолчанию задана
    else
      *uin = (uint32_t)*uin;  // если никакого флага, то стандартный
  }
  // тут десятичная система считсления числа
  int base = 10;
  if (current_options->field_type == 'x' ||
      current_options->field_type == 'X' || current_options->field_type == 'p')
    base = 16;
  if (current_options->field_type == 'o') base = 8;
  char uint_str[64] = {0};  // буфер с запасом для записи числа в строку
  s21_size_t len = uint2str(*uin, uint_str, base);
  if (current_options->field_type == 'o' &&
      current_options->flags & FLAG_HASH && current_options->precision < len) {
    current_options->flags |= FLAG_PRECISION;
    current_options->precision = len + 1;
  }
  if (current_options->field_type == 'X')
    for (int i = 0; uint_str[i];) {  // если флаг - буквы в большие
      if (uint_str[i] > '9')
        uint_str[i++] -= 32;
      else
        i++;
    }
  int delta = 0;
  // точность дополняет нулями число спереди
  if (current_options->precision > len) {
    delta = current_options->precision - len;  // разница
    len = current_options->precision;  // бОльшая точность - новая длина
    current_options->precision = delta;  // для дополнения нулями
    delta = 0;  // для дальнейшего использования переменной
  } else  // только если число короче точности
    current_options->precision = 0;
  if (!(current_options->width) && ((current_options->field_type == 'p') ||
                                    (current_options->flags & FLAG_HASH &&
                                     ((current_options->field_type == 'x') ||
                                      (current_options->field_type == 'X'))))) {
    *str++ = '0';
    if (current_options->field_type == 'X')
      *str++ = 'X';
    else
      *str++ = 'x';
    len += 2;
  }
  if (current_options->width > len) delta = current_options->width - len;
  if (current_options->field_type == 'p' ||
      (current_options->flags & FLAG_HASH &&
       (current_options->field_type == 'x' ||
        current_options->field_type == 'X')))
    delta -= 2;
  if (current_options->flags & FLAG_PLUS && current_options->field_type == 'p')
    delta--;
  char c = ' ';  // пробел или ноль, в зависимости от флага
  if (current_options->flags & FLAG_ZERO &&
      !(current_options->flags & FLAG_PRECISION))
    c = '0';
  int i = 0;
  if (current_options->flags & FLAG_MINUS &&
      (current_options->field_type == 'p' ||
       (current_options->field_type == 'x' &&
        current_options->flags & FLAG_HASH) ||
       (current_options->field_type == 'X' &&
        current_options->flags & FLAG_HASH))) {
    if (current_options->flags & FLAG_PLUS &&
        current_options->field_type == 'p') {
      *str++ = '+';
      len++;
    } else if (current_options->flags & FLAG_SPACE &&
               current_options->field_type == 'p') {
      *str++ = ' ';
      delta--;
      len++;
    }
    *str++ = '0';
    if (current_options->field_type == 'X' &&
        current_options->flags & FLAG_HASH)
      *str++ = 'X';
    else if (current_options->field_type == 'p' ||
             (current_options->field_type == 'X' &&
              current_options->flags & FLAG_HASH))
      *str++ = 'x';
    len += 2;
  }
  // символы в начале до заданной ширины
  if (!(current_options->flags & FLAG_MINUS) && delta > 0) {
    if ((current_options->field_type == 'p' ||
         (current_options->field_type == 'x' &&
          current_options->flags & FLAG_HASH) ||
         (current_options->field_type == 'X' &&
          current_options->flags & FLAG_HASH)) &&
        c == '0') {
      if (current_options->flags & FLAG_PLUS &&
          current_options->field_type == 'p') {
        *str++ = '+';
        len++;
      }
      *str++ = '0';
      if (current_options->field_type == 'X' &&
          current_options->flags & FLAG_HASH)
        *str++ = 'X';
      else if (current_options->field_type == 'p' ||
               (current_options->field_type == 'X' &&
                current_options->flags & FLAG_HASH))
        *str++ = 'x';
      len += 2;
    }
    while (delta--) {
      *str++ = c;
      len++;
    }
    if ((current_options->field_type == 'p' ||
         (current_options->field_type == 'x' &&
          current_options->flags & FLAG_HASH) ||
         (current_options->field_type == 'X' &&
          current_options->flags & FLAG_HASH)) &&
        c == ' ') {
      if (current_options->flags & FLAG_PLUS &&
          current_options->field_type == 'p') {
        *str++ = '+';
        len++;
      }
      *str++ = '0';
      if (current_options->field_type == 'X' &&
          current_options->flags & FLAG_HASH)
        *str++ = 'X';
      else if (current_options->field_type == 'p' ||
               (current_options->field_type == 'x' &&
                current_options->flags & FLAG_HASH))
        *str++ = 'x';
      len += 2;
    }
  }
  while (current_options->precision--) {
    *str++ = '0';  // нули впереди до нужной точности
  }
  for (; uint_str[i];) *str++ = uint_str[i++];  // непосредственно вывод числа
  // пробелы в конце до заданной ширины
  // нули нельзя, т.к. это изменит целое число
  if ((current_options->flags & FLAG_MINUS) && delta > 0)
    while (delta--) {
      *str++ = ' ';
      len++;
    }
  return len;
}

// записывает дробное десятичное df в строку df_str
// возвращает количество записанных в строку df_str символов
s21_size_t df2str(double *df, char *df_str,
                  struct print_options *current_options) {
  s21_size_t len = 0;
  double whole_df = 0.0;  // для целой части числа lf
  double f_df = modf(*df, &whole_df);  // дробная часть
  int whole_len = len_whole((int_fast64_t)whole_df, 10);
  char *whole_buf = (char *)calloc(abs(whole_len) + 10, sizeof(char));
  if (!whole_buf) exit(1);  // память пожрал доглоносик
  uint2str((long int)whole_df, whole_buf,
           10);  // целую часть записываем в буфер
  char *fraction_buff =
      (char *)calloc(current_options->precision + 10, sizeof(char));
  if (!fraction_buff) exit(1);  // память пожрал доглоносик
  int i = 0;                    // для округления
  int next_digit = 0;
  for (i = 0; i <= (int)current_options->precision; i++) {
    f_df = f_df * 10;  // старший разряд в целую часть
    if (i < (int)current_options->precision) fraction_buff[i] = (int)f_df + '0';
    // преврящаем в символ цифры - корректируем по ASCII
    else  // не забыть округлить все число по последнему разряду
      if ((int)f_df > 4) next_digit++;
    f_df -= (int)f_df % 10;  // очищаем целую часть для следующей цифры
  }
  fraction_buff[--i] = '\0';  // корректно завершим строку
  while (i > 0 && next_digit) {  // округление дробной части
    fraction_buff[--i] += next_digit--;
    if (fraction_buff[i] > '9') {
      fraction_buff[i] = '0';
      next_digit = 1;
    } else
      next_digit = 0;
  }
  i = whole_len;
  while (i > 0 && next_digit) {  // округление целой части
    whole_buf[--i] += next_digit--;
    if (whole_buf[i] > '9') {
      whole_buf[i] = '0';
      next_digit = 1;
    } else
      next_digit = 0;
  }
  if (next_digit) {
    *df_str++ = '1';
    len++;
  }
  for (i = 0; whole_buf[i]; len++)  // записываем целую часть
    *df_str++ = whole_buf[i++];
  *df_str++ = '.';  // точку
  len++;
  for (i = 0; fraction_buff[i]; len++)  // записываем дробную часть
    *df_str++ = fraction_buff[i++];
  free(whole_buf);
  free(fraction_buff);
  return len;
}

// печатает дробное десятичное df в строку str в соответствии с флагами
// возвращает количество записанных в строку str символов
s21_size_t sprint_double(char *str, double *df,
                         struct print_options *current_options) {
  int negative = *df < 0 ? 1 : 0;  // для минуса, если отрицательное число
  *df = negative ? *df * -1 : *df;  // сделаем положительным
  s21_size_t len = 0;

  int exp_df = 0;  // для экспоненты
  frexpl(*df, &exp_df);
  char *df_str =
      (char *)calloc(abs(exp_df) + 10, sizeof(char));  // буфер для записи
  if (!df_str) exit(1);  // память пожрал доглоносик
  // строка достаточного размера + знак, точка, ноль, запас
  exp_df = 0;
  double mantissa_df = *df;
  if (*df != 0.0) {
    while (mantissa_df > 2) {
      mantissa_df = mantissa_df / 10;
      exp_df++;
    }
    while (mantissa_df < 1) {
      mantissa_df = mantissa_df * 10;
      exp_df--;
    }
    if (negative) mantissa_df = -mantissa_df;
  }
  char format[20] = {0};
  int f = 0, s;
  if (current_options->field_type == 'G' ||
      current_options->field_type == 'g') {
    if (exp_df < -4 || exp_df >= (int)current_options->precision) {
      // условия при которых печатаем в экспоненциальной форме
      if (current_options->field_type == 'G') current_options->field_type = 'E';
      if (current_options->field_type == 'g') current_options->field_type = 'e';
      if (negative) mantissa_df = -mantissa_df;
      int dlen = df2str(&mantissa_df, df_str, current_options);
      s = 0;
      while (df_str[s])
        if (df_str[s++] == '.') break;
      if (s <= dlen)
        while (df_str[--dlen] == '0') {
          ;
        }
      if (negative) mantissa_df = -mantissa_df;
      current_options->flags |= FLAG_PRECISION;
      current_options->precision = dlen + 1 - s;
    } else {  // иначе - в десятичной форме
      if (!((int)*df - *df)) {  // если целое - отбрасываем точку
        format[f++] = '%';
        if (current_options->flags & FLAG_MINUS) format[f++] = '-';
        if (current_options->flags & FLAG_PLUS) format[f++] = '+';
        if (current_options->flags & FLAG_SPACE) format[f++] = ' ';
        if (current_options->flags & FLAG_HASH) format[f++] = '#';
        if (current_options->flags & FLAG_ZERO) format[f++] = '0';
        format[f++] = '*';
        format[f++] = '.';
        format[f++] = '*';
        format[f++] = 'i';
        format[f++] = '\0';
        len = s21_sprintf(df_str, format, current_options->width,
                          current_options->precision, (int)*df);
        current_options->flags &= ~FLAG_PLUS;
        // особенность печати целых - надо исправить на беззнаковое
        while (df_str[0] == '+' || df_str[0] == '-' || df_str[0] == '0') {
          s = 0;
          while (df_str[s]) {
            df_str[s] = df_str[s + 1];
            s++;
          }
          len--;
        }
      } else {  // или выводим без дробных нулей
        if (current_options->field_type == 'G')
          current_options->field_type = 'F';
        if (current_options->field_type == 'g')
          current_options->field_type = 'f';
        len = df2str(df, df_str, current_options);
        s = 0;
        int tmp = len, del = 0;
        while (df_str[s])
          if (df_str[s++] == '.') break;
        if (s <= tmp)
          while (df_str[--tmp] == '0') {
            df_str[tmp] = '\0';
            del++;
          }
        current_options->flags |= FLAG_PRECISION;
        current_options->precision = len - s - del;
      }
    }
  }
  if (current_options->field_type != 'G' &&
      current_options->field_type != 'g') {
    if (current_options->field_type == 'E' ||
        current_options->field_type == 'e') {
      // вывоим в экспоненциальном формате с основанием 10
      f = 0;
      int ftmp_w = 0;
      format[f++] = '%';
      if (current_options->flags & FLAG_MINUS) format[f++] = '-';
      if (current_options->flags & FLAG_PLUS) format[f++] = '+';
      if (current_options->flags & FLAG_SPACE) format[f++] = ' ';
      if (current_options->flags & FLAG_HASH) format[f++] = '#';
      if (current_options->flags & FLAG_ZERO) format[f++] = '0';
      format[f++] = '*';
      format[f++] = '.';
      format[f++] = '*';
      if (current_options->field_type == 'e') {
        format[f++] = 'f';
        format[f++] = 'e';
      }
      if (current_options->field_type == 'E') {
        format[f++] = 'F';
        format[f++] = 'E';
      }
      format[f++] = '%';
      format[f++] = '+';
      format[f++] = '.';
      format[f++] = '2';
      format[f++] = 'd';
      format[f++] = '\0';
      int lw = len_whole(exp_df, 10);
      if (current_options->flags & FLAG_MINUS)
        ftmp_w = current_options->precision + negative + 2;
      else {
        if (lw <= 2)
          ftmp_w = current_options->width - lw - 3;
        else
          ftmp_w = current_options->width - lw;
      }
      if (negative) negative = 0;  // корректировка знака для рекурсии
      len = s21_sprintf(df_str, format, ftmp_w, current_options->precision,
                        mantissa_df, exp_df);
      s = 0;
      if (df_str[s] == '+' || df_str[s] == '-') {
        while (df_str[s]) {
          df_str[s] = df_str[s + 1];
          s++;
        }
        len--;
      }
      current_options->flags &= ~FLAG_PLUS;
    } else {  // дальше вывод обычного дробного
      if (current_options->flags & FLAG_PRECISION &&
          !current_options->precision) {
        // если дробной части нету
        int_fast64_t whole_in = negative ? -1 * roundl(*df) : roundl(*df);
        // вернем знак и напечатаем как целое - частный случай
        len = sprint_int(df_str, &whole_in, current_options);
        // с дробной точкой если флаг
        if (current_options->flags & FLAG_HASH) {
          len++;
          df_str[s21_strlen(df_str)] = '.';
        }
        //    особенность печати целых - надо исправить на беззнаковое
        while (df_str[0] == '+' || df_str[0] == '-') {
          s = 0;
          if (df_str[s] == '+' || df_str[s] == '-') {
            while (df_str[s]) {
              df_str[s] = df_str[s + 1];
              s++;
            }
            len--;
          }
        }
      } else  // иначе - печатаем дробное заданной точности
        len = df2str(df, df_str, current_options);
    }
  }
  int delta = 0;
  if (current_options->width > len + negative)
    delta = current_options->width - len;
  if (negative || current_options->flags & FLAG_PLUS) delta--;
  char c = ' ';
  if (current_options->flags & FLAG_ZERO) c = '0';
  if (current_options->flags & FLAG_ZERO ||
      current_options->flags & FLAG_MINUS) {
    if (negative) {
      *str++ = '-';
      len++;
    } else if (current_options->flags & FLAG_PLUS) {
      *str++ = '+';
      len++;
      current_options->flags &= ~FLAG_PLUS;
    }
  }
  if (!(current_options->flags & FLAG_MINUS) && delta > 0)
    while (delta--) {
      *str++ = c;
      len++;
    }
  if (negative && !(current_options->flags & FLAG_ZERO)) {
    *str++ = '-';
    len++;
  } else if (current_options->flags & FLAG_PLUS) {
    *str++ = '+';
    len++;
  }
  for (int i = 0; df_str[i];) {
    *str++ = df_str[i++];  // буфер в строку
  }
  if (delta > 0)
    while (delta--) {
      *str++ = ' ';
      len++;
    }
  free(df_str);
  return len;
}

// вычисляет длину (количество цифр в системе base) целого числа n
int len_whole(int_fast64_t n, int base) {
  int len = 1;
  for (; n /= base; ++len)
    ;
  return len;
}

// записывает дробное десятичное lf в строку lf_str
// возвращает количество записанных в строку lf_str символов
s21_size_t lf2str(long double *lf, char *lf_str,
                  struct print_options *current_options) {
  s21_size_t len = 0;

  long double whole_lf = 0.0;  // для целой части числа lf
  long double f_lf = modfl(*lf, &whole_lf);  // дробная часть
  int whole_len = len_whole((int_fast64_t)whole_lf, 10);
  char *whole_buf = (char *)calloc(abs(whole_len) + 10, sizeof(char));
  if (!whole_buf) exit(1);  // память пожрал доглоносик
  uint2str((long int)whole_lf, whole_buf,
           10);  // целую часть записываем в буфер
  char *fraction_buff =
      (char *)calloc(current_options->precision + 10, sizeof(char));
  if (!fraction_buff) exit(1);  // память пожрал доглоносик
  int i = 0;                    // для округления
  int next_digit = 0;
  for (i = 0; i <= (int)current_options->precision; i++) {
    f_lf = f_lf * 10;  // старший разряд в целую часть
    if (i < (int)current_options->precision) fraction_buff[i] = (int)f_lf + '0';
    // преврящаем в символ цифры - корректируем по ASCII
    else  // не забыть округлить все число по последнему разряду
      if ((int)f_lf > 4) next_digit++;
    f_lf -= (int)f_lf % 10;  // очищаем целую часть для следующей цифры
  }
  fraction_buff[--i] = '\0';  // корректно завершим строку
  while (i > 0 && next_digit) {  // округление дробной части
    fraction_buff[--i] += next_digit--;
    if (fraction_buff[i] > '9') {
      fraction_buff[i] = '0';
      next_digit = 1;
    } else
      next_digit = 0;
  }
  i = whole_len;
  while (i > 0 && next_digit) {  // округление целой части
    whole_buf[--i] += next_digit--;
    if (whole_buf[i] > '9') {
      whole_buf[i] = '0';
      next_digit = 1;
    } else
      next_digit = 0;
  }
  if (next_digit) {
    *lf_str++ = '1';
    len++;
  }
  for (i = 0; whole_buf[i]; len++)  // записываем целую часть
    *lf_str++ = whole_buf[i++];
  *lf_str++ = '.';  // точку
  len++;
  for (i = 0; fraction_buff[i]; len++)  // записываем дробную часть
    *lf_str++ = fraction_buff[i++];
  free(whole_buf);
  free(fraction_buff);
  return len;
}

// печатает дробное десятичное lf в строку str в соответствии с флагами
// возвращает количество записанных в строку str символов
s21_size_t sprint_ldouble(char *str, long double *lf,
                          struct print_options *current_options) {
  int negative = *lf < 0 ? 1 : 0;  // для минуса, если отрицательное число
  *lf = negative ? *lf * -1 : *lf;  // сделаем положительным
  s21_size_t len = 0;

  int exp_lf = 0;  // для экспоненты
  frexpl(*lf, &exp_lf);
  char *lf_str =
      (char *)calloc(abs(exp_lf) + 10, sizeof(char));  // буфер для записи
  if (!lf_str) exit(1);  // память пожрал доглоносик
  // строка достаточного размера + знак, точка, ноль, запас

  exp_lf = 0;
  long double mantissa_lf = *lf;
  if (*lf != 0.0L) {
    while (mantissa_lf > 2) {
      mantissa_lf = mantissa_lf / 10;
      exp_lf++;
    }
    while (mantissa_lf < 1) {
      mantissa_lf = mantissa_lf * 10;
      exp_lf--;
    }
    if (negative) mantissa_lf = -mantissa_lf;
  }
  char format[20] = {0};
  int f = 0, s;
  if (current_options->field_type == 'G' ||
      current_options->field_type == 'g') {
    if (exp_lf < -4 || exp_lf >= (int)current_options->precision) {
      // условия при которых печатаем в экспоненциальной форме
      if (current_options->field_type == 'G') current_options->field_type = 'E';
      if (current_options->field_type == 'g') current_options->field_type = 'e';
      if (negative) mantissa_lf = -mantissa_lf;
      int llen = lf2str(&mantissa_lf, lf_str, current_options);
      s = 0;
      while (lf_str[s])
        if (lf_str[s++] == '.') break;
      if (s <= llen)
        while (lf_str[--llen] == '0') {
          ;
        }
      if (negative) mantissa_lf = -mantissa_lf;
      current_options->flags |= FLAG_PRECISION;
      current_options->precision = llen + 1 - s;
    } else {  // иначе - в десятичной форме
      if (!((long int)*lf - *lf)) {  // если целое - отбрасываем точку
        format[f++] = '%';
        if (current_options->flags & FLAG_MINUS) format[f++] = '-';
        if (current_options->flags & FLAG_PLUS) format[f++] = '+';
        if (current_options->flags & FLAG_SPACE) format[f++] = ' ';
        if (current_options->flags & FLAG_HASH) format[f++] = '#';
        if (current_options->flags & FLAG_ZERO) format[f++] = '0';
        format[f++] = '*';
        format[f++] = '.';
        format[f++] = '*';
        format[f++] = 'l';
        format[f++] = 'i';
        format[f++] = '\0';

        len = s21_sprintf(lf_str, format, current_options->width,
                          current_options->precision, (long int)*lf);
        current_options->flags &= ~FLAG_PLUS;
        // особенность печати целых - надо исправить на беззнаковое
        while (lf_str[0] == '+' || lf_str[0] == '-' || lf_str[0] == '0') {
          s = 0;
          while (lf_str[s]) {
            lf_str[s] = lf_str[s + 1];
            s++;
          }
          len--;
        }
      } else {  // или выводим без дробных нулей

        if (current_options->field_type == 'G')
          current_options->field_type = 'F';
        if (current_options->field_type == 'g')
          current_options->field_type = 'f';
        len = lf2str(lf, lf_str, current_options);
        s = 0;
        int tmp = len, del = 0;
        while (lf_str[s])
          if (lf_str[s++] == '.') break;
        if (s <= tmp)
          while (lf_str[--tmp] == '0') {
            lf_str[tmp] = '\0';
            del++;
          }
        current_options->flags |= FLAG_PRECISION;
        current_options->precision = len - s - del;
      }
    }
  }
  if (current_options->field_type != 'G' &&
      current_options->field_type != 'g') {
    if (current_options->field_type == 'E' ||
        current_options->field_type == 'e') {
      // вывоим в экспоненциальном формате с основанием 10

      f = 0;
      int ftmp_w = 0;
      format[f++] = '%';
      if (current_options->flags & FLAG_MINUS) format[f++] = '-';
      if (current_options->flags & FLAG_PLUS) format[f++] = '+';
      if (current_options->flags & FLAG_SPACE) format[f++] = ' ';
      if (current_options->flags & FLAG_HASH) format[f++] = '#';
      if (current_options->flags & FLAG_ZERO) format[f++] = '0';
      format[f++] = '*';
      format[f++] = '.';
      format[f++] = '*';
      format[f++] = 'L';
      if (current_options->field_type == 'e') {
        format[f++] = 'f';
        format[f++] = 'e';
      }
      if (current_options->field_type == 'E') {
        format[f++] = 'F';
        format[f++] = 'E';
      }
      format[f++] = '%';
      format[f++] = '+';
      format[f++] = '.';
      format[f++] = '2';
      format[f++] = 'd';
      format[f++] = '\0';
      int lw = len_whole(exp_lf, 10);
      if (current_options->flags & FLAG_MINUS)
        ftmp_w = current_options->precision + negative + 2;
      else {
        if (lw <= 2)
          ftmp_w = current_options->width - lw - 3;
        else
          ftmp_w = current_options->width - lw;
      }
      if (negative) negative = 0;  // корректировка знака для рекурсии
      len = s21_sprintf(lf_str, format, ftmp_w, current_options->precision,
                        mantissa_lf, exp_lf);
      // while (lf_str[0] == '+' || lf_str[0] == '-') {
      s = 0;
      if (lf_str[s] == '+' || lf_str[s] == '-') {
        while (lf_str[s]) {
          lf_str[s] = lf_str[s + 1];
          s++;
        }
        len--;
      }
      //}
      // current_options->flags &= ~FLAG_PLUS;
    } else {  // дальше вывод обычного дробного
      if (current_options->flags & FLAG_PRECISION &&
          !current_options->precision) {
        // если дробной части нету
        int_fast64_t whole_in = negative ? -1 * roundl(*lf) : roundl(*lf);
        // вернем знак и напечатаем как целое - частный случай
        len = sprint_int(lf_str, &whole_in, current_options);
        // с дробной точкой если флаг
        if (current_options->flags & FLAG_HASH) {
          len++;
          lf_str[s21_strlen(lf_str)] = '.';
        }
        //   особенность печати целых - надо исправить на беззнаковое
        s = 0;
        if (lf_str[s] == '+' || lf_str[s] == '-') {
          while (lf_str[s]) {
            lf_str[s] = lf_str[s + 1];
            s++;
          }
          len--;
        }
      } else  // иначе - печатаем дробное заданной точности
        len = lf2str(lf, lf_str, current_options);
    }
  }
  int delta = 0;
  if (current_options->width > len + negative)
    delta = current_options->width - len;
  if (negative || current_options->flags & FLAG_PLUS) delta--;
  char c = ' ';
  if (current_options->flags & FLAG_ZERO) c = '0';
  if (current_options->flags & FLAG_ZERO ||
      current_options->flags & FLAG_MINUS) {
    if (negative) {
      *str++ = '-';
      len++;
    } else if (current_options->flags & FLAG_PLUS) {
      *str++ = '+';
      len++;
      current_options->flags &= ~FLAG_PLUS;
    }
  }
  if (!(current_options->flags & FLAG_MINUS) && delta > 0)
    while (delta--) {
      *str++ = c;
      len++;
    }
  if (negative && !(current_options->flags & FLAG_ZERO)) {
    *str++ = '-';
    len++;
  } else if (current_options->flags & FLAG_PLUS) {
    *str++ = '+';
    len++;
  }

  for (int i = 0; lf_str[i];) {
    *str++ = lf_str[i++];  // буфер в строку
  }
  if (delta > 0)
    while (delta--) {
      *str++ = ' ';
      len++;
    }

  free(lf_str);
  return len;
}

// печатает в строку нечисловое значение
int nan2str(char *str, int *negative, const int *nan,
            struct print_options *current_options) {
  char *nan_msg[3] = {"nan", "inf"};
  char out[4] = {'\0'};  // промежуточный буфер
  int i = 0;
  if (current_options->flags & FLAG_PLUS && !*negative) {
    out[i++] = '+';  // печатаем знак, если флаг
  }
  if (*negative) {  // или минус
    out[i++] = '-';
  }
  while (*nan_msg[*nan - 1]) out[i++] = *nan_msg[*nan - 1]++;
  if (current_options->field_type == 'F' ||
      current_options->field_type == 'E' || current_options->field_type == 'G')
    for (i = 0; out[i];) {
      if (out[i] != '-' && out[i] != '+')
        out[i++] -= 32;
      else
        i++;
    }
  int len = sprint_string(str, out, current_options);  // записываем
  return len;
}

// парсит тип поля для вывода
// возвращает 1 если прочитан, 0 если нет
// определяет тип и записывает в строку из параметра
s21_size_t parse_type(const char *format, struct print_options *current_options,
                      va_list *param, char *str, s21_size_t *fs_len) {
  s21_size_t len = 0;
  // переменные вынесены из кейсов, потому что мак иначе не понимает
  char c;
  int_fast64_t in;
  long double Lf;  // для long double
  double df;       // для double
  int nan;         // для не числовых значений
  int negative;    // для знака
  char *s;
  uint_fast64_t uin;

  // сохраним тип и одновременно передвинем указатель на следующий символ
  switch (current_options->field_type = *(format + len++)) {
    case 'c':
      c = (char)va_arg(*param, int);
      // печатаем символ в соответствии с флагами и увеличиваем счетчик
      *fs_len += sprint_char(str + *fs_len, &c, current_options);
      break;
    case 'd':
    case 'i':  // в задании нету, но тут оно полностью идентично с d
      in = va_arg(*param, int_fast64_t);
      *fs_len += sprint_int(str + *fs_len, &in, current_options);
      break;
    case 'g':
    case 'G':
    case 'E':
    case 'e':
    case 'F':
    case 'f':
      nan = 0;       // для не числовых значений
      negative = 0;  // для знака
      if (!(current_options->flags & FLAG_PRECISION)) {
        current_options->precision = 6;  // точность по умолчанию
        current_options->flags |= FLAG_PRECISION;
      }
      if (current_options->flags & FLEN_L) {
        Lf = va_arg(*param, long double);  // (16 байт)
        negative = signbit(Lf);  // читает бит, содержащий знак числа
        // в том числе подходит для NAN, INF -INF
        nan = isnan(Lf) + 2 * abs(isinf(Lf));
        if (!nan)
          *fs_len += sprint_ldouble(str + *fs_len, &Lf, current_options);
      } else {
        df = va_arg(*param, double);  // (8 байт)
        negative = signbit(df);  // читает бит, содержащий знак числа
        // в том числе подходит для NAN, INF -INF
        nan = isnan(df) + 2 * abs(isinf(df));
        if (!nan) *fs_len += sprint_double(str + *fs_len, &df, current_options);
      }
      if (nan)
        *fs_len += nan2str(str + *fs_len, &negative, &nan, current_options);
      break;
    case 's':
      s = va_arg(*param, char *);
      // печатаем символ в соответствии с флагами и увеличиваем счетчик
      *fs_len += sprint_string(str + *fs_len, s, current_options);
      break;
    case 'X':
    case 'x':
    case 'o':
    case 'p':
    case 'u':
      uin = va_arg(*param, uint_fast64_t);
      *fs_len += sprint_uint(str + *fs_len, &uin, current_options);
      break;
    case '%':
      *(str + (*fs_len)++) = '%';  // копирование символа %
      // одновременно с успешной записью увеличиваем счетчик
      // вывод только процента, все флаги игнорируются
      break;
      // default:
      //   len--;  // текущий символ - неподходящий или поле закончилось,
      //   вернемся break;
  }
  return len;
}

// парсит формат для вывода
// возвращает количество символов в определении формата
// состояние опция записывает в current_options
s21_size_t parse_format(const char *format,
                        struct print_options *current_options, va_list *param) {
  s21_size_t len = 0;
  len += parse_flags(format + len, &current_options->flags);
  if (*(format + len) == '*') {
    len++;  // особый случай - ширина в параметрах
    int width = va_arg(*param, int);
    if (width < 0) {
      // повторяет поведение оригинала
      // если подать отрицательную ширину, минус принимается как флаг
      current_options->flags |= FLAG_MINUS;
      current_options->width = -width;
    } else
      current_options->width = width;
  } else
    len += parse_num(format + len, &current_options->width);
  if (*(format + len) == '.') {
    current_options->flags |= FLAG_PRECISION;
    len++;  // если указана точка, пропускаем ее и читаем точность поля
    if (*(format + len) == '*') {
      len++;  // особый случай - точность в параметрах
      int precision = va_arg(*param, int);
      if (precision < 0) {
        // не может быть отрицательной
        current_options->precision = 0;
      } else
        current_options->precision = precision;
    } else
      len += parse_num(format + len, &current_options->precision);
  }
  len += parse_length(format + len, &current_options->flags);
  return len;
}

int s21_sprintf(char *str, const char *format, ...) {
  s21_size_t f_len = 0;  // счетчик символов чтения форматной строки
  s21_size_t fs_len = 0;  // счетчик фактически записанных символов

  va_list param;  // для параметров
  va_start(param, format);

  // читаем форматную строку, пока она не закончится
  while (*(format + f_len) != '\0') {
    if (*(format + f_len) == '%') {
      struct print_options current_options = {0};  // набор опций для формата
      f_len += parse_format(format + f_len + 1, &current_options, &param) + 1;
      //  f_len тут надо увеличить на размер считанного поля формата И "%"

      if (parse_type(format + f_len, &current_options, &param, str, &fs_len))
        // fs_len увеличиваем на количество успешно записанных символов
        f_len++;
      else {
        ;  // f_len = -1;  //  ОШИБКА??? Если не указать тип поля
      }
      // оригинал не выходит и непонятно как продолжает вывод:
      // печатается процент без флага %
      // остальные флаги печатаются прямо в строку
      // астериски заменяются значениями из параметров
      //
    } else {
      *(str + fs_len++) = *(format + f_len++);  // простое копирование символа
      // одновременно с успешной записью увеличиваем счетчики
    }
  }
  *(str + fs_len) = '\0';  // завершим строку нулем, как полагается
  va_end(param);  // завершим работу с параметрами
  return fs_len;  // вернем количество фактически записанных символов
}