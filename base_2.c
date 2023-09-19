#include <stdlib.h>
#include "main.h"

/**
 * print_binary - Convert and print number in binary formt
 * @num: The number to be converted
 *
 * Return: Number of printed characters
 */
int print_binary(unsigned int num)
{
	int printed_chars = 0;
	int length = 0;
	char *ptr;
	unsigned int temp = num;
	int i, j = 0;

	while (temp > 0)
	{
		temp /= 2;
		length++;
	}

	ptr = malloc((length + 1) * sizeof(char));

	if (ptr == NULL)
		return (-1);

	i = length - 1;
	while (i >= 0)
	{
		ptr[i] = num % 2 + '0';
		num /= 2;
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
