#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

/* functions.c */
void print_char(va_list args, int *len);
void print_str(va_list args, int *i, int *len);
void print_statments(char format, int *len);
void print_percent(int *i, int *len);

/* functions1.c */
int print_zero_and_INTMAX(int *i, int *len, int integer);
int print_int(va_list args, int *i, int *len);
int print_unsigned_int(va_list args, int *i, int *len);


/* functions2.c */
void change_sign(int *integer, int *temp);
void free_statments(char *string, char *str);
void string_reverse(int *j, int *k, char *string, char *str);
void number_len(int *integer, int *digit);

#endif
