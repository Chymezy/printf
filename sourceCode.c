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

		_putchar(c);
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
		_putchar('%');
		return (1);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		return (print_number(va_arg(args, int)));
	}

	_putchar('%');
	_putchar(specifier);
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
		_putchar('-');
		printed_chars++;
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		printed_chars++;
	}
	else
	{
		while (num != 0)
		{
			_putchar('0' + (num % 10));
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

	while (*str)
	{
		_putchar(*str);
		printed_chars++;
		str++;
	}

	return (printed_chars);
}

