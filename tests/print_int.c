#include "../main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	printf("TEST 1 PRINT INT (d): %d\n", 123);
	_printf("TEST 1 PRINT INT (d): %d\n", 123);

	printf("TEST 2 PRINT INT (i): %i\n", -123);
	_printf("TEST 2 PRINT INT (i): %i\n", -123);

	printf("TEST 3 PRINT INT (d): %d\n", INT_MAX);
	_printf("TEST 3 PRINT INT (d): %d\n", INT_MAX);

	printf("TEST 4 PRINT INT (i): %i\n", INT_MIN);
	_printf("TEST 4 PRINT INT (i): %i\n", INT_MIN);

	printf("TEST 5 PRINT INT (d): %d\n", 0);
	_printf("TEST 5 PRINT INT (d): %d\n", 0);

	printf("TEST 6 PRINT INT (i): %i\n", 0);
	_printf("TEST 6 PRINT INT (i): %i\n", 0);

	return (0);
}
