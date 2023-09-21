#include "main.h"

/**
 * print_pointer - Print a pointer's memory address
 * @args: The argument list containing the pointer to print
 *
 * Return: The number of characters printed
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	uintptr_t address = (uintptr_t)ptr;
	int len = 0;
	char hexChars[] = "0123456789abcdef";

	_putchar('0');
	_putchar('x');
	len += 2;

	int numDigits = 0;
	uintptr_t temp = address;

	do {
		numDigits++;
		temp /= 16;
	} while (temp > 0);

	char *hexAddress = (char *)malloc(numDigits + 1);

	if (hexAddress == NULL)
	{
		return (-1);
	}

	for (int i = numDigits - 1; i >= 0; i--)
	{
		hexAddress[i] = hexChars[address & 0xF];
		address /= 16;
	}
	hexAddress[numDigits] = '\0';

	for (int i = 0; hexAddress[i] != '\0'; i++)
	{
		_putchar(hexAddress[i]);
		len++;
	}

	free(hexAddress);
	return (len);
}

