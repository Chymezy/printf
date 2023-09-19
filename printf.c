#include "main.h"
#include <stdint.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte) on success,
 *         -1 on error, and it may exit the program on critical error
 */
int _printf(const char *format, ...)
{
	int printed_chars;

	conver_t funct_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	/** call a parser function */

	printed_chars = parser(format, funct_list, args);
	va_end(args);

	return (printed_chars);
}

