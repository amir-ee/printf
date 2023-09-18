#include "main.h"

/**
 * get_size - Extracts size specifier from a format string
 * @format: The input format string
 * @i: A pointer to the current position in the format string
 *
 * Description:
 * This function parses the format string starting from the position pointed
 * to by 'i' and extracts the size specifier if it exists. The size specifier
 * can be 'l' for long or 'h' for short. If no size specifier is found, the
 * function returns 0.
 *
 * Return:
 * The extracted size specifier constant (S_LONG or S_SHORT) or 0 if no
 * size specifier is found.
 */

int get_size(const char *format, int *i)
{
	int python_lose = *i + 1;
	int tyson = 0;

	if (format[python_lose] == 'l')
		tyson = S_LONG;
	else if (format[python_lose] == 'h')
		tyson = S_SHORT;

	if (tyson == 0)
		*i = python_lose - 1;
	else
		*i = python_lose;

	return (tyson);
}
