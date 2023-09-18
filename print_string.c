#include "main.h"

/**
 * print_string - Print a string to stdout
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int print_string(const char *str)
{
    int printed_chars = 0;

    while (*str)
    {
        putchar(*str);
        printed_chars++;
        str++;
    }

    return (printed_chars);
}
