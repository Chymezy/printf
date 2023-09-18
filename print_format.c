#include "main.h"

/**
 * print_format - Print the formatted output based on the format string
 * @format: The format string
 * @args: The variable argument list
 * Return: Number of characters printed
 */
int print_format(const char *format, va_list args)
{
	int printed_chars = 0;

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				_putchar('%');
				return (-1);
			}
			printed_chars += handle_format_specifier(*format, args);
		}
		format++;
	}

	return (printed_chars);
}

