#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1
 */
int _putchar(char c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c == BUF_FLUSH || i >= BUFFER_SIZE)
	{
		write(1, &buffer, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buffer[i++] = c;

	return (1);
}

/**
 * _puts - prints a string to stdout
 * @str: string to print
 * Return: number of chars printed
 */
int _puts(char *str)
{
	int len = 0;

	while (*str)
		len += _putchar(*str++);
	return (len);
}
