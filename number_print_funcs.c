#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 * Return: number of digits printed
 */
int print_number(int n)
{
	int chars_printed = 0;

	if (n < 0)
	{
		_putchar('-');
		chars_printed++;
		n = -n;
	}
	if (n / 10)
		chars_printed += print_number(n / 10);
	_putchar((n % 10) + '0');
	chars_printed++;
	return (chars_printed);
}

/**
 * print_int - prints an integer
 * @ap: argument pointer
 * @f: pointer to struct containing flags
 * Return: number of characters printed
 */
int print_int(va_list ap, Flags *f)
{
	(void)f;
	return (print_number(va_arg(ap, int)));
}

/**
 * print_unsigned - prints an unsigned integer
 * @ap: argument pointer
 * @f: pointer to struct containing flags
 * Return: number of characters printed
 */
int print_unsigned(va_list ap, Flags *f)
{
	(void)f;
	return (print_number(va_arg(ap, unsigned int)));
}
