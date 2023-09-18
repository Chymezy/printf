#include "main.h"

/**
 * handle_format_specifier - Handle a format specifier
 * @specifier: The format specifier character
 * @args: The variable argument list
 * Return: Number of characters printed for the specifier
 */
int handle_format_specifier(char specifier, va_list args)
{
	int printed_chars = 0;

	if (specifier == 'c')
	{
		int c = va_arg(args, int);

		_putchar(c);
		printed_chars++;
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);

		if (str != NULL)
			printed_chars += print_string(str);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);

		printed_chars += print_number(num);
	}
		/* Handle additional specifiers */
		/* Implement logic for these specifiers */
	else
	{
		_putchar('%');
		_putchar(specifier);
		printed_chars += 2; /* Return 2 for unsupported format specifier */
	}

	return (printed_chars);
}

