#include <stdio.h>
#include "main.h"

int main(void)
{
	int len;

	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d]\n", len);
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	_printf("Number:[%d]\n", 12345);
	_printf("Negative:[%i]\n", -67890);

	return (0);
}

