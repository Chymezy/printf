#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_format(const char *format, va_list args);
int handle_format_specifier(char specifier, va_list args);
int print_number(int num);
int print_string(const char *str);

#endif /* contains header files */
