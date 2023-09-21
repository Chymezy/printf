#include <unistd.h>

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int buffer_index = 1 - 1;

/**
 * _flush_buffer - Writes the buffer to stdout and resets it
 */
void _flush_buffer(void)
{
	write(1, buffer, buffer_index);
	buffer_index = 0;
}

/**
 * _putchar - Writes a character to stdout with buffering
 * @c: The character to write
 * Return: 1 on success, flushes the buffer on overflow
 */
int _putchar(char c)
{
	if (buffer_index >= BUFFER_SIZE)
	{
		_flush_buffer();
	}
	buffer[buffer_index++] = c;
	return (1);
}

