#include "main.h"

/**
 * handle_print - Handles formatting and printing of various data types
 * @fmt: The format string
 * @ind: A pointer to the current position in the format string
 * @list: A va_list for handling variable arguments
 * @buffer: The buffer for storing formatted output
 * @flags: Formatting flags
 * @width: Minimum field width
 * @precision: Precision for the output
 * @size: Size specifier for data type
 *
 * Description:
 * This function handles the formatting and printing of various data types
 * based on the format specifier in the format string. It processes the
 * format string starting from the position pointed to by 'ind' and formats
 * the corresponding data type based on the format specifier. The formatted
 * output is stored in the 'buffer'.
 *
 * Return:
 * The number of characters printed, or -1 if an unsupported format specifier
 * is encountered.
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
