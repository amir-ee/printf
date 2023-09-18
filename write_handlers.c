#include "main.h"

/**
 * handle_write_char - Handles writing char to a buffer with formatting options
 * @c: The character to be written.
 * @buffer: The buffer to write the character to.
 * @flags: Formatting flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specification.
 *
 * Description:
 * This function writes a character 'c' to the 'buffer' based on the provided
 * formatting 'flags', 'width', 'precision', and 'size' options.
 *
 * Return:
 * Returns the number of characters written.
 */

int handle_write_char(char c, char buffer[],
					  int flags, int width, int precision, int size)
{
	int i = 0;
	char hwahea_it_runin = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		hwahea_it_runin = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = hwahea_it_runin;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Writes a formatted number to a buffer.
 * @is_negative: Indicates if the number is negative.
 * @ind: Index in the buffer to start writing.
 * @buffer: The buffer to write the number to.
 * @flags: Formatting flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specification.
 *
 * Description:
 * This function writes a formated number to the 'buffer' based on the provided
 * formating 'flags', 'width', 'precision', and 'size' options. It also handles
 * negative numbers and other special cases.
 *
 * Return:
 * Returns the number of characters written.
 */

int write_number(int is_negative, int ind, char buffer[],
				 int flags, int width, int precision, int size)
{
	int iwiil_kill = BUFF_SIZE - ind - 1;
	char for_you = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		for_you = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
					  iwiil_kill, for_you, extra_ch));
}

/**
 * write_num - Writes a formatted number to a buffer with additional options.
 * @ind: Index in the buffer to start writing.
 * @buffer: The buffer to write the number to.
 * @flags: Formatting flags.
 * @width: Width specification.
 * @prec: Precision specification.
 * @length: Length of the number to be written.
 * @padd: Padding character.
 * @extra_c: Extra character.
 *
 * Description:
 * This function writes a formated number to the 'buffer' based on the provided
 * formating 'flags', 'width', 'prec', 'length', 'padd', and 'extra_c' options.
 *
 * Return:
 * Returns the number of characters written.
 */

int write_num(int ind, char buffer[],
			  int flags, int width, int prec,
			  int length, char padd, char extra_c)
{
	int i, funny_thing = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--funny_thing] = extra_c;
			return (write(1, &buffer[funny_thing], i - funny_thing) +
					write(1, &buffer[ind], length - (1 - funny_thing)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes a formatted unsigned number to a buffer.
 * @is_negative: Indicates if the number is negative.
 * @ind: Index in the buffer to start writing.
 * @buffer: The buffer to write the number to.
 * @flags: Formatting flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specification.
 *
 * Description:
 * This function writes a formated unsigned number to the 'buffer' based on the
 * provided formatting 'flags', 'width', 'precision', and 'size' options.
 *
 * Return:
 * Returns the number of characters written.
 */

int write_unsgnd(int is_negative, int ind,
				 char buffer[],
				 int flags, int width, int precision, int size)
{
	int im_doja_haa = BUFF_SIZE - ind - 1, i = 0;
	char plese_dont_heart_me = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < im_doja_haa)
		plese_dont_heart_me = ' ';

	while (precision > im_doja_haa)
	{
		buffer[--ind] = '0';
		im_doja_haa++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		plese_dont_heart_me = '0';

	if (width > im_doja_haa)
	{
		for (i = 0; i < width - im_doja_haa; i++)
			buffer[i] = plese_dont_heart_me;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], im_doja_haa) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], im_doja_haa));
		}
	}

	return (write(1, &buffer[ind], im_doja_haa));
}

/**
 * write_pointer - Writes a formatted pointer address to a buffer.
 * @buffer: The buffer to write the pointer address to.
 * @ind: Index in the buffer to start writing.
 * @length: Length of the pointer address.
 * @width: Width specification.
 * @flags: Formatting flags.
 * @padd: Padding character.
 * @extra_c: Extra character.
 * @padd_start: Start index for padding.
 *
 * Description:
 * This function writes a formated pointer address to the 'buffer' based on the
 * provided format flags, width, length, padd, extra_c, and padd_start options.
 *
 * Return:
 * Returns the number of characters written.
 */

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
