#include "main.h"

char *base_converter(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *str;

	rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';

	do
	{
		*--str = rep[num % base];
		num /= base;
	}

	while (num != 0);
	return (str);
}
