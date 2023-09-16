#include "main.h"
#include <stdarg.h>

/**
 * _printf - printf clone will behave exactly as the original
 * @format: list of argument types passed to the function
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *cursor;
	int (*print_func)(va_list, Flags *);
	int chars_printed = 0;

	(void)print_func;

	va_start(ap, format);
	/* FIXME: add conditions */
	for (cursor = format; *cursor; cursor++)
	{
		if (*cursor != '%')
		{
			_putchar(*cursor);
			chars_printed++;
		}
		else
		{
			cursor++;
			print_func = print_mux(*cursor);
			chars_printed += print_func(ap, NULL);
		}
	}
	_putchar(BUF_FLUSH);
	va_end(ap);

	return (chars_printed);
}
