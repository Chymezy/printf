#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of charaacters printed (excluding null bytes)
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char *);

			if (str != NULL)
			{
				while (*str)
				{
					putchar(*str);
					str++;
					printed_chars++;
				}
			}
		}
		else if (*format == '%')
		{
			putchar('%')
			printed_chars++;
		}
		else
		{
			putchar('%');
			putchar(*format);
			printed_chars += 2;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
