#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a character to stdout
 * @list: A va_list containing the character to be printed
 *
 * Description:
 * This function retrieves a character from the va_list and prints.
 *
 * Return: The number of characters printed (1).
 */

int print_char(va_list list)
{
	return (_putchar(va_arg(list, int)));
}

/**
 * print_string - Prints a string to stdout
 * @list: A va_list containing the string to be printed
 *
 * Description:
 * This function retrieves a string from the va_list and prints it to stdout.
 * If the string is NULL, it prints "(null)" instead.
 *
 * Return: The number of characters printed.
 */

int print_string(va_list list)
{
	char *str = va_arg(list, char *);

	if (!str)
		str = "(null)";

	int count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * _printf - Prints formatted text to stdout
 * @format: The format string containing directives
 *
 * Description:
 * This function prints formatted text to the standard output (stdout) based on
 * the format string and optional arguments.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count = 0;

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				count += print_char(list);
			}
			else if (*format == 's')
			{
				count += print_string(list);
			}
			else if (*format == '%')
			{
				count += _putchar('%');
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		format++;
	}
	va_end(list);
	return (count);
}
