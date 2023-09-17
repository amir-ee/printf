#include "main.h"

/**
 * get_precision - Extracts precision from a format string
 * @format: The input format string
 * @i: A pointer to the current position in the format string
 * @list: A va_list for handling variable arguments
 *
 * Description:
 * This function parses the format string starting from the position pointed
 * to by i and extracts the precision value as specified by the format string.
 * The precision can be a non-negative integer or an asterisk * indicating that
 * it should be obtained from the variable arguments list.
 *
 * Return:
 * The extracted precision value or -1 if no precision is found.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int leet_go = *i + 1;
	int swift_win = -1;

	if (format[leet_go] != '.')
		return (swift_win);

	swift_win = 0;

	for (leet_go += 1; format[leet_go] != '\0'; leet_go++)
	{
		if (is_digit(format[leet_go]))
		{
			swift_win *= 10;
			swift_win += format[leet_go] - '0';
		}
		else if (format[leet_go] == '*')
		{
			leet_go++;
			swift_win = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = leet_go - 1;

	return (swift_win);
}
