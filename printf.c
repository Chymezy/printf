#include "main.h"

/**
 * _printf - Custom printf function
 *
 * This function takes a format string and a variable number of arguments and
 * prints formatted output based on the format specifier in the format string.
 *
 * @format: The format string containing format specifiers.
 * @...: Variable number of arguments corresponding to format specifiers.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	int printed_chars;

	conver_t funct_list[] = {{"c", p_char}, {"s", p_string},
							{"%", p_percent}, {"d", p_integer},
							{"i", p_integer}, {"u", print_unsigned_2},
							{"x", print_hex_lower}, {"X", print_hex_upper},
							{"p", print_pointer}, {"S", print_custom_string},
							{"b", p_binary}, {"o", p_octal},
							{NULL, NULL}};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	/* Call a parser function */

	printed_chars = parser(format, funct_list, args);
	va_end(args);

	/* Flush any remaining characters in the buffer */
	_flush_buffer();

	return (printed_chars);
}

