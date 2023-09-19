#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct convert - Struct to map conversion specifiers to functions
 * @sym: The conversion specifier symbol
 * @f: The corresponding function for the conversion specifier
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

int _putchar(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[], va_list args);
int p_char(va_list);
int p_string(va_list args);
int p_percent(va_list);
int print_unsgined_number(unsigned int n);
int print_number(va_list);
int p_integer(va_list);
int p_binary(va_list);

#endif
