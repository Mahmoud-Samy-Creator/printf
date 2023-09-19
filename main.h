#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args, int *i, int *len);
int print_str(va_list args, int *i, int *len);
int print_statments(char format, int *len);
int print_percent(int *i, int *len);
int print_int(va_list args, int *i, int *len);
unsigned long int print_in(va_list args, int *i, int *len);

#endif
