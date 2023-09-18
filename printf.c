#include "main.h"

int print_format(const char *format, va_list args);
int handle_format_specifier(char specifier, va_list args);
int print_number(int num);
int print_string(const char *str);

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte) on success,
 *         -1 on error, and it may exit the program on critical error
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = print_format(format, args);
	va_end(args);

	return (printed_chars);
}
