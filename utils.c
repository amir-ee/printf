#include "main.h"

/**
 * _is_digit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int _is_digit(char c) { return (c >= '0' && c <= '9'); }

/**
 * _strlen - returns the length of a string
 * @s: string to check length
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: integer value of string
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do
	{
		if (*s == '-')
			sign *= -1;
		else if (_is_digit(*s))
			num = num * 10 + (*s - '0');
		else if (num > 0)
			break;
	}
	while (*s++);
	return (num * sign);
}
