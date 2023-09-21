#include "main.h"
#include <stdlib.h>

/**
 * print_unsigned_2 - Print an unsigned integer
 * @args: The argument list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_unsigned_2(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;
	int digits = 0;

	/* Calculate the number of digits */
	do {
		digits++;
		temp /= 10;
	} while (temp > 0);

	/* Allocate memory for the string representation */
	char *str = (char *)malloc(digits + 1);

	if (str == NULL)
	{
		return (-1); /* Memory allocation failure */
	}

	/* Convert the unsigned integer to a string */
	for (int i = digits - 1; i >= 0; i--)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	str[digits] = '\0'; /* Null-terminate the string */

	/* Print the string */
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		len++;
	}

	free(str);  /* Free the dynamically allocated memory */
	return (len); /* Return the number of characters printed */
}

