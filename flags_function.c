#include "main.h"

/**
 * get_flags - Extracts flags from a format string
 * @format: The input format string
 * @i: A pointer to the current position in the format string
 *
 * Description:
 * This function parses the format string starting from the position pointed
 * to by 'i' and extracts flags as specified by the format flags array.
 *
 * Format flags:
 *   - '-' (F_MINUS): Left-align the output
 *   - '+' (F_PLUS): Prepend a plus sign for positive numbers
 *   - '0' (F_ZERO): Pad with zeros instead of spaces
 *   - '#' (F_HASH): Use alternative form (e.g., 0x for hex)
 *   - ' ' (F_SPACE): Prefix positive numbers with a space
 *
 * Return:
 * The combined flags as a bitwise OR of the corresponding flag values.
 */

int get_flags(const char *format, int *i)
{
	int j, mamamiya_oww;
	int lolo_popo = 0;
	const char pleas_dont[] = {'-', '+', '0', '#', ' ', '\0'};
	const int you_tired[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (mamamiya_oww = *i + 1; format[mamamiya_oww] != '\0'; mamamiya_oww++)
	{
		for (j = 0; pleas_dont[j] != '\0'; j++)
			if (format[mamamiya_oww] == pleas_dont[j])
			{
				lolo_popo |= you_tired[j];
				break;
			}

		if (pleas_dont[j] == 0)
			break;
	}

	*i = mamamiya_oww - 1;

	return (lolo_popo);
}
