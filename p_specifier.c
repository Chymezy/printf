#include "main.h"

/**
 * print_pointer - Print a pointer's memory address.
 * @args: The argument list containing the pointer to print.
 *
 * Return: The number of characters printed.
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	uintptr_t address = (uintptr_t)ptr;
	int i,  len = 0;
	char hexChars[] = "0123456789abcdef";
	int numDigits = 0;
	uintptr_t temp = address;
	char *hexAddress;

	len = isPointerArgumentNull(ptr);

	while (temp > 0)
	{
		numDigits++;
		temp /= 16;
	}

	hexAddress = (char *)malloc(numDigits + 1);

	if (hexAddress == NULL)
		return (-1);

	for (i = numDigits - 1; i >= 0; i--)
	{
		hexAddress[i] = hexChars[address & 0xF];
		address /= 16;
	}
	hexAddress[numDigits] = '\0';

	for (i = 0; hexAddress[i] != '\0'; i++)
	{
		_putchar(hexAddress[i]);
		len++;
	}

	free(hexAddress);
	return (len);
}

/**
 * isPointerArgumentNull - Check if the pointer argument passed is NULL
 * @ptr: Pointer to check
 *
 * Return: -1 if the pointer is NULL
 */
int isPointerArgumentNull(void *ptr)
{
	if (ptr == NULL)
	{
		_printf("(nil)");
		return (-1);
	}

	_putchar('0');
	_putchar('x');

	return (2);
}
