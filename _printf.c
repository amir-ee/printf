#include "main.h"
/**
 * _printf - printf function for printing
 * @format: printf format
 * Return: int length of the inpue.
*/
int _printf(const char *format, ...)
{
	fm format_redear[] = {{"%c", print_char}, {"%s", print_string},
							{"%d", print_integer}, {"%i", print_integer}, {NULL, NULL}};
	int i = -1, j = 0, len = 1;
	va_list arg;

	va_start(arg, format);

	while (format[++i])
	{
		j = 0;

		if (format[i] == 37)
		{
			if (format[i + 1] == 37) /* printf "%%" */
			{
				len += _putchar(format[i + 1]);
				i += 1;
				continue;
			}
			while (j < 20)
			{
				if (format[i + 1] == 32)
					i++;

				else if (format[i + 1] == format_redear[j].f[1])
				{
					len += format_redear[j].print(arg);
					i++;
					break;
				} /*  */
				else
					j++;
			}
		}
		else
			len += _putchar(format[i]);
	}
	return (len - 1);
}
