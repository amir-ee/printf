#include "main.h"

/**
 * print_binary - prints a binary number
 * @ap: argument to print
 * @flags: struct containing flags
 * Return: number of characters printed
 */
int print_binary(va_list ap, Flags *flags)
{
	unsigned int num;
	int count = 0;
	char *str;

	(void)flags;

	num = va_arg(ap, unsigned int);
	str = base_converter(num, 2, 0);

	count += _puts(str);
	return (count);
}

/**
 * print_hex - prints a hexadecimal number
 * @ap: argument to print
 * @flags: struct containing flags
 * Return: number of characters printed
 */
int print_hex(va_list ap, Flags *f)
{
	unsigned int num;
	int count = 0;
	char *str;

	(void)f;

	num = va_arg(ap, unsigned int);
	str = base_converter(num, 16, 1);
	count += _puts(str);
	return (count);
}

/**
 * print_hex_upper - prints a hexadecimal number
 * @ap: argument to print
 * @flags: struct containing flags
 * Return: number of characters printed
 */
int print_hex_upper(va_list ap, Flags *f)
{
	unsigned int num;
	int count = 0;
	char *str;

	(void)f;

	num = va_arg(ap, unsigned int);
	str = base_converter(num, 16, 0);
	count += _puts(str);

	return (count);
}

/**
 * print_octal - prints an octal number
 * @ap: argument to print
 * @flags: struct containing flags
 * Return: number of characters printed
 */
int print_octal(va_list ap, Flags *f)
{
	unsigned int num;
	int count = 0;
	char *str;

	(void)f;

	num = va_arg(ap, unsigned int);
	str = base_converter(num, 8, 0);
	count += _puts(str);
	return (count);
}
