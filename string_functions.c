#include "main.h"

/**
 * p_char - Print a character
 * @args: The argument list containing the character to print
 * Return: The number of characters printed
 */
int p_char(va_list args)
{
	char value;

	value = va_arg(args, int);
	_putchar(value);
	return (1);
}

/**
 * p_string - Print a string
 * @args: The argument list containing the string to print
 * Return: The number of characters printed
 */
int p_string(va_list args)
{
	int i;
	const char *s;

	s = va_arg(args, const char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * p_percent - Print a percent symbol
 * @args: The argument list (unused)
 * Return: The number of characters printed
 */
int p_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}

/**
 * p_integer - Print an integer
 * @args: The argument list containing the integer to print
 * Return: The number of characters printed
 */
int p_integer(va_list args)
{
	int n;

	n = print_number(args);
	return (n);
}

