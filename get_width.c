#include "main.h"

/**
 * get_width - Extracts width from a format string
 * @format: The input format string
 * @i: A pointer to the current position in the format string
 * @list: A va_list for handling variable arguments
 *
 * Description:
 * This function parses the format string starting from the position pointed
 * to by 'i' and extracts the width value as specified by the format string.
 * The width can be a non-negative integer or an asterisk (*) indicating that
 * it should be obtained from the variable arguments list.
 *
 * Return:
 * The extracted width value.
 */

int get_width(const char *format, int *i, va_list list)
{
	int fuck_o;
	int hahah = 0;

	for (fuck_o = *i + 1; format[fuck_o] != '\0'; fuck_o++)
	{
		if (is_digit(format[fuck_o]))
		{
			hahah *= 10;
			hahah += format[fuck_o] - '0';
		}
		else if (format[fuck_o] == '*')
		{
			fuck_o++;
			hahah = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = fuck_o - 1;

	return (hahah);
}
