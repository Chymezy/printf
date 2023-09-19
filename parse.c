#include "main.h"

/**
 * parser - Parses and processes format specifiers in a string.
 * @format: The format string containing format specifiers.
 * @funct_list: An array of structs specifying format specifiers and
 *              their corresponding functions.
 * @args: The variable argument list.
 *
 * Return: The number of characters printed (excluding null byte) on success,
 *         -1 on error, and it may exit the program on critical error.
 */
int parser(const char *format, conver_t funct_list[], va_list args)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++) /* Iterates through the main str */
	{
		if (format[i] == '%') /* Checks for format specifiers */
		{
			/* Iterates through struct to find the right func */
			for (j = 0; funct_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == funct_list[j].sym[0])
				{
					r_val = funct_list[j].f(args);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (funct_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars += 2;
				}
				else
					return (-1);
			}
			i = i + 1; /* Updating i to skip format symbols */
		}
		else
		{
			_putchar(format[i]); /* Call the write function */
			printed_chars++;
		}
	}
	return (printed_chars);
}

