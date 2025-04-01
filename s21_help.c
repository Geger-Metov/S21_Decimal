#include "s21_decimal.h"

void s21_clear_decimal(s21_decimal *dst) {
  memset(dst, 0, sizeof(s21_decimal));
}

void s21_set_sign(s21_decimal *dst, int sign) {
  if (sign) {
    dst->bits[3] |= (1 << 31);
  } else {
    dst->bits[3] &= ~(1 << 31);
  }
}

int s21_get_sign(s21_decimal dst) { return ((dst.bits[3] >> 31) & 1); }

int get_number_degree(s21_decimal dst) {
  return (dst.bits[3] >> 16) & 0xFF;  // 0xFF = 0b11111111 = 255
}

int isNull(s21_decimal dec) {
  return (!dec.bits[0] && !dec.bits[1] && !dec.bits[2]);
}

// временно для truncate, как напишем s21_div, наверное, прекратить
// использование
int ten_div(int bit) { return bit / 10; }

int float_cnt_degree(char *str) {
  int result = 0;
  char *ptr = str;
  while (*ptr) {
    if (*ptr == 'E') {
      ++ptr;
      if (*ptr == '+' || *ptr == '-') {
        ++ptr;
      }
      result = strtol(ptr, NULL, 10);
      break;
    }
    ++ptr;
  }
  return result;
}

s21_decimal from_str_to_decimal(char *str) {
  int dig_cnt = 6;
  s21_decimal tmp;
  s21_clear_decimal(&tmp);
  char *ptr = str;
  int junk = 0;

  // int exp = float_cnt_degree(str);

  while (*ptr) {
    if (*ptr == '.') {
      ++ptr;
    } else if (*ptr == 'E') {
      break;
    } else if (*ptr >= '0' && *ptr <= '9') {
      // if ((unsigned)tmp.bits[0] != 0xFFFFFFFF)
      int dig = *ptr - '0';
      junk += dig * pow(10, dig_cnt);
      --dig_cnt;
      ++ptr;
    }
  }
  s21_from_int_to_decimal(junk, &tmp);
  return tmp;
}

int set_degree(s21_decimal *dst, int degree) {
  return dst->bits[3] |= degree << 16;
}

int is_set_bit(int number, int index) { return !!(number & (1U << index)); }

int s21_decimal_is_set_bit(s21_decimal decimal, int index) {
  return is_set_bit(decimal.bits[index / 32], index % 32);
}