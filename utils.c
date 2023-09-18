#include "main.h"

/**
 * is_printable - Check if a character is a printable ASCII character.
 * @c: The character to check.
 *
 * Description:
 * This function checks whether a given character 'c' is a printable ASCII
 * character, i.e., falls within the range of 32 to 126 in ASCII.
 *
 * Return:
 * Returns 1 if 'c' is printable, 0 otherwise.
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append the hexadecimal code of an ASCII character to a buffer.
 * @ascii_code: The ASCII code of the character to convert to hexadecimal.
 * @buffer: The buffer to which the hexadecimal code will be appended.
 * @i: The index in the buffer to start appending.
 *
 * Description:
 * This function appends the hexadecimal representation of an ASCII code 'ascii_code'
 * to a character buffer 'buffer' starting at the specified index 'i'.
 *
 * Return:
 * Returns the number of characters appended to the buffer, which is always 3.
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Check if a character is a digit.
 * @c: The character to check.
 *
 * Description:
 * This function checks whether a given character 'c' is a digit (0-9).
 *
 * Return:
 * Returns 1 if 'c' is a digit, 0 otherwise.
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Convert a number to a different size.
 * @num: The number to be converted.
 * @size: The target size (S_LONG, S_SHORT, or S_INT).
 *
 * Description:
 * This function converts a signed integer 'num' to a different size (long, short, or int)
 * based on the specified 'size' parameter.
 *
 * Return:
 * Returns the converted integer value.
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Convert an unsigned number to a different size.
 * @num: The unsigned number to be converted.
 * @size: The target size (S_LONG, S_SHORT, or S_INT).
 *
 * Description:
 * This function converts an unsigned integer 'num' to a different size (long, short, or int)
 * based on the specified 'size' parameter.
 *
 * Return:
 * Returns the converted integer value.
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
