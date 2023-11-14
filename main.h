#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int printf_str(char *atika);
int printf_c(char c);
int esra_format(char sps, va_list printf);
int printf_d_i(long num, int base, int upper);
int printf_b(long num, int base);
int printf_S(char *esra);
int printf_s(char *str);
int printf_h_l(va_list printf, char sps);
int printf_p(void *ptr);
int _strlen(char *str);
int printf_R(char *s);
int printf_rev(char *str);
#endif
