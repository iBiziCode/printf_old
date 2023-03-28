#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
int _printf(const char *format, ...);
#endif
