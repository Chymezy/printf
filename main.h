#ifndef MAIN_H
#define MAIN_H


/* Function prototypes */

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte) on success,
 *         -1 on error, and it may exit the program on critical error
 */
int _printf(const char *format, ...);

/**
 * print_format - Print the formatted output based on the format string
 * @format: The format string
 * @args: The variable argument list
 * Return: Number of characters printed
 */
int print_format(const char *format, va_list args);

/**
 * handle_format_specifier - Handle a format specifier
 * @specifier: The format specifier character
 * @args: The variable argument list
 * Return: Number of characters printed for the specifier
 */
int handle_format_specifier(char specifier, va_list args);

/**
 * print_number - Print an integer to stdout
 * @num: The integer to be printed
 * Return: The number of characters printed
 */
int print_number(int num);

/**
 * print_string - Print a string to stdout
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int print_string(const char *str);

/**
 * _putchar - print character to stdout
 * @c: character to be printed
 * Return: The character ASCII value
 */
int _putchar(char c);

#endif /* MAIN_H */

