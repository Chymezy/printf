#include "main.h"

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

