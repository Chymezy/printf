#include "main.h"

/**
 * print_hex - Print an integer in hexadecimal format.
 * @args: The argument list containing the integer to print.
 * @uppercase: 1 for uppercase (X), 0 for lowercase (x).
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);

	int maxDigits = 0;
	unsigned int temp = num;

	while (temp > 0)
	{
		maxDigits++;
		temp /= 16;
	}

	char *hex = (char *)malloc(maxDigits + 1);

	if (hex == NULL)
		return (-1);
	const char *hexCharsLower = "0123456789abcdef";
	const char *hexCharsUpper = "0123456789ABCDEF";
	const char *hexChars = (uppercase ? hexCharsUpper : hexCharsLower);

	int i = maxDigits - 1;

	while (i >= 0)
	{
		hex[i] = hexChars[num % 16];
		num /= 16;
		i--;
	}
	hex[maxDigits] = '\0';
	int printed_chars = 0;

	i = 0;
	while (hex[i] != '\0')
	{
		_putchar(hex[i]);
		printed_chars++;
		i++;
	}
	free(hex);
	return (printed_chars);
}

/**
 * print_hex_lower - Print an integer in lowercase hexadecimal format (%x).
 * @args: The argument list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_hex_lower(va_list args)
{
	return (print_hex(args, 0)); /* Call print_hex with lowercase characters */
}

/**
 * print_hex_upper - Print an integer in uppercase hexadecimal format (%X).
 * @args: The argument list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(va_list args)
{
	return (print_hex(args, 1)); /* Call print_hex with uppercase characters */
}

