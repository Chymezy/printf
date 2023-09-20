#include "main.h"

/**
 * p_octal - Function to handle 'o' conversion specifier
 * @args: The argument to convert
 *
 * Return: The total number of characters printed
 */
int p_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = 0;

	if (num == 0)
		printed_chars += _putchar('0');
	else
		printed_chars += print_octal(num);

	return (printed_chars);
}

/**
 * print_octal - Function that convert and print a number in
 * octal format
 * @num: The numbet to be converted and printed
 *
 * Return: The total number of characters printed
 */
int print_octal(unsigned int num)
{
	int printed_chars = 0;
	int length = 0;
	char *ptr;
	unsigned int temp = num;
	int i, j = 0;

	while (temp > 0)
	{
		temp /= 8;
		length++;
	}

	ptr = malloc((length + 1) * sizeof(char));

	if (ptr == NULL)
		return (-1);

	i = length - 1;
	while (i >= 0)
	{
		ptr[i] = num % 8 + '0';
		num /= 8;
		i--;
	}

	ptr[length] = '\0';

	while (ptr[j] != '\0')
	{
		_putchar(ptr[j]);
		printed_chars++;
		j++;
	}

	free(ptr);

	return (printed_chars);
}
