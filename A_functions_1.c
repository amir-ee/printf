#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @types: A va_list containing the argument to be printed
 * @buffer: The buffer to store the printed characters
 * @flags: Flags controlling the format (e.g., padding with zeros)
 * @width: Minimum width of the output
 * @precision: Minimum number of digits to be printed
 * @size: Optional size specifier for the argument
 *
 * Description: This function prints an unsigned integer using various
 * formatting options specified by the flags, width, precision, and size
 * parameters.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
				   int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @types: A va_list containing the argument to be printed
 * @buffer: The buffer to store the printed characters
 * @flags: Flags controlling the format (e.g., padding with zeros)
 * @width: Minimum width of the output
 * @precision: Minimum number of digits to be printed
 * @size: Optional size specifier for the argument
 *
 * Description: This function prints an unsigned integer in octal format using
 * various formatting options specified by the flags, width precision, and size
 * parameters. It supports the '#' flag for adding a leading '0' when the input
 * is non-zero.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list types, char buffer[],
				int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal format
 * @types: A va_list containing the argument to be printed
 * @buffer: The buffer to store the printed characters
 * @flags: Flags controlling the format (e.g., padding with zeros)
 * @width: Minimum width of the output
 * @precision: Minimum number of digits to be printed
 * @size: Optional size specifier for the argument
 *
 * Description: This function prints an unsigned integer in lowercase hexadcmal
 * format using various formatting options specified by the flags, width,
 * precision, and size parameters.
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
					  int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
					   flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Print an unsigned integer in uppercase hexadecimal format
 * @types: A va_list containing the argument to be printed
 * @buffer: The buffer to store the printed characters
 * @flags: Flags controlling the format (e.g., padding with zeros)
 * @width: Minimum width of the output
 * @precision: Minimum number of digits to be printed
 * @size: Optional size specifier for the argument
 *
 * Description: This function print an unsigned integer in upercase hexadecimal
 * format using various formatting options specified by the flags, width,
 * precision, and size parameters.
 *
 * Return: The number of characters printed.
 */
int print_hexa_upper(va_list types, char buffer[],
					 int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
					   flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints an unsigned integer in hexadecimal format
 * @types: A va_list containing the argument to be printed
 * @map_to: A mapping of characters for hexadecimal digits
 * @buffer: The buffer to store the printed characters
 * @flags: Flags controlling the format (e.g., padding with zeros)
 * @flag_ch: The character for the '#' flag (e.g., 'x' or 'X')
 * @width: Minimum width of the output
 * @precision: Minimum number of digits to be printed
 * @size: Optional size specifier for the argument
 *
 * Description: This function prints an unsigned integer in hexadecimal format
 * using various formatting options specified by the flags width precision, and
 * size parameters. It also suports the '#' flag for adding '0x' or '0X' prefix
 * when the input is non-zero.
 *
 * Return: The number of characters printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
			   int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
