#include "main.h"

/**
 * is_printable - Checks if a character is printable
 * @c: The character to be checked
 *
 * Description:
 * This function checks whether a character falls within the printable ASCII
 * range (from 32 to 126) and returns 1 if it is printable, otherwise 0.
 *
 * Return:
 * 1 if the character is printable, 0 otherwise.
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends the hexadecimal representation of a character to a buffer
 * @ascii_code: The ASCII code of the character to be converted
 * @buffer: The buffer to which the hexadecimal representation is appended
 * @i: The current index in the buffer
 *
 * Description:
 * This function appends the hexadecimal representation of the given ASCII code
 * to the buffer at the specified index 'i'. It returns the number of characters
 * (3) appended to the buffer.
 *
 * Return:
 * The number of characters (3) appended to the buffer.
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks if a character is a digit
 * @c: The character to be checked
 *
 * Description:
 * This function checks whether a character is a digit (0-9) and returns 1
 * if it is a digit, otherwise 0.
 *
 * Return:
 * 1 if the character is a digit, 0 otherwise.
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Converts a number to a specific size
 * @num: The number to be converted
 * @size: The desired size (S_LONG or S_SHORT)
 *
 * Description:
 * This function converts a given number to a specific size (long int or short int)
 * based on the 'size' parameter and returns the converted number.
 *
 * Return:
 * The converted number with the specified size.
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
 * convert_size_unsgnd - Converts an unsigned number to a specific size
 * @num: The unsigned number to be converted
 * @size: The desired size (S_LONG or S_SHORT)
 *
 * Description:
 * This function converts a given unsigned number to a specific size (unsigned long int
 * or unsigned short int) based on the 'size' parameter and returns the converted number.
 *
 * Return:
 * The converted unsigned number with the specified size.
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
