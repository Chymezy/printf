#include "main.h"

/**
 * print_custom_string - Print a custom string with special character handling.
 * @args: The argument list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_custom_string(va_list args)
{
	int i, len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		len += p_string_literal("(null)");
		return (len);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		char current = str[i];

		if ((current < 32 && current >= 0) || current >= 127)
		{
			len += _putchar('\\');
			len += _putchar('x');
			len += print_hex_2(current);
		}
		else
		{
			len += _putchar(current);
		}
	}

	return (len);
}

/**
 * print_hex_2 - Print a character as a hexadecimal value.
 * @c: The character to print in hexadecimal.
 *
 * Return: The number of characters printed.
 */
int print_hex_2(char c)
{
	char hexCharsUpper[] = "0123456789ABCDEF";

	int len = 0;
	unsigned char uc = (unsigned char)c;
	char hex[2];

	hex[0] = hexCharsUpper[uc / 16];
	hex[1] = hexCharsUpper[uc & 15];

	len += _putchar(hex[0]);
	len += _putchar(hex[1]);

	return (len);
}

