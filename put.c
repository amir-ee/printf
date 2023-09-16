#include "main.h"

/**
 * _putchar - print a character.
 * @c: char.
 * Return: return 1.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print a character.
 * @s: pointer to character string.
 * Return: return 1.
*/

int _puts(char *s)
{
	int i = -1;

	while (s[++i])
		_putchar(s[i]);
	return (i);
}
