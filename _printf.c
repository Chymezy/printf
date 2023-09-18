#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte) on success,
 *         -1 on error, and it may exit the program on critical error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
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
			else if (*format == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else
			{
				printed_chars += handle_format_specifier(*format, args);
			}
		}
		format++;
	}
	va_end(args);

	return (printed_chars);
}

