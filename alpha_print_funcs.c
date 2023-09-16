#include "main.h"

/**
 * print_char - prints a character
 * @ap: argument pointer
 * @f: pointer to struct containing flags
 * Return: 1 if successful
 */
int print_char(va_list ap, Flags *f)
{
	(void)f;
	return (_putchar(va_arg(ap, int)));
}

/**
 * print_str - prints a string
 * @ap: argument pointer
 * @f: pointer to struct containing flags
 * Return: number of characters printed
 */
int print_str(va_list ap, Flags *f)
{
	char *str = va_arg(ap, char *);

	(void)f;
	if (!str)
		str = NULL_STRING;
	return (_puts(str));
}
