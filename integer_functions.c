#include "main.h"

/**
 * print_number - Print a signed integer
 * @args: The argument list containing the integer to print
 * Return: The number of characters printed
 */
int print_number(va_list args)
{
	int num;
	int divisor;
	int len;
	unsigned int absolute;

	num = va_arg(args, int);
	divisor = 1;
	len = 0;

	if (num < 0)
	{
		len += _putchar('-');
		absolute = num * -1;
	}
	else
		absolute = num;

	while (absolute / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor != 0)
	{
		len += _putchar('0' + absolute / divisor);
		absolute %= divisor;
		divisor /= 10;
	}

	return (len);
}

/**
 * print_unsigned_number - Print an unsigned integer
 * @n: The unsigned integer to print
 * Return: The number of characters printed
 */
int print_unsigned_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;

	num = n;

	while (num / check > 9)
	{
		check *= 10;
	}

	while (check != 0)
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}

	return (len);
}
