#include "main.h"

/**
 * print_mux - selects the correct print function
 * @s: format specifier
 * Return: pointer to correct print function
 */
int (*print_mux(char s))(va_list ap, Flags *f)
{
	/* TODO: Add the rest of the specifiers */
	PrintSpecifierPair print_pairs[] = {
			{'c', print_char},			{'s', print_str},			{'d', print_int},
			{'i', print_int},				{'%', print_percent}, {'b', print_binary},
			{'u', print_unsigned},	{'o', print_octal},		{'x', print_hex},
			{'X', print_hex_upper}, {'\0', NULL}};
	int i;

	for (i = 0; i < ACTIVE_SPECIFIERS_NUM; i++)
		if (print_pairs[i].specifier == s)
			return (print_pairs[i].print_func);

	return (NULL);
}

/**
 * flag_mux - selects the correct flag function
 * @s: format specifier
 * @f: pointer to struct containing flags
 * Return: 1 if a flag was turned on, 0 otherwise
 */
int flag_mux(char s, Flags *f)
{
	/* TODO: adjust prototype and impelment */
	(void)s;
	(void)f;
	return (0);
}
