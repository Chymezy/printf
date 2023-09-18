#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>

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
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				putchar('%');
				return (-1);
			}
			printed_chars += handle_format_specifier(*format, args);
		}
		format++;
	}

	return (printed_chars);
}

/**
 * handle_format_specifier - Handle a format specifier
 * @specifier: The format specifier character
 * @args: The variable argument list
 * Return: Number of characters printed for the specifier
 */
int handle_format_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
	{
		int c = va_arg(args, int);

		putchar(c);
		return (1);
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);

		if (str != NULL)
			return (print_string(str));
	}
	else if (specifier == '%')
	{
		putchar('%');
		return (1);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		return (print_number(va_arg(args, int)));
	}

	putchar('%');
	putchar(specifier);
	return (2); /* Return 2 for unsupported format specifier */
}

/**
 * print_number - Print an integer to stdout
 * @num: The integer to be printed
 * Return: The number of characters printed
 */
int print_number(int num)
{
	int printed_chars = 0;

	if (num < 0)
	{
		putchar('-');
		printed_chars++;
		num = -num;
	}

	if (num == 0)
	{
		putchar('0');
		printed_chars++;
	}
	else
	{
		while (num != 0)
		{
			putchar('0' + (num % 10));
			printed_chars++;
			num /= 10;
		}
	}

	return (printed_chars);
}

/**
 * print_string - Print a string to stdout
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int print_string(const char *str)
{
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		putchar(*str);
		printed_chars++;
		str++;
	}

	return (printed_chars);
}

