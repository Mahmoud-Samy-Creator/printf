#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args, int *i);
int print_str(va_list args, int *i);
int print_statments(char format);
int print_percent(int *i);

#endif
