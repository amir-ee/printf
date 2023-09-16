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
	printf("TEST 0 PRINT binary: %b\n", 98);
	_printf("TEST 0 PRINT binary: %b\n", 98);

	printf("TEST 1 PRINT binary: %b\n", 0);
	_printf("TEST 1 PRINT binary: %b\n", 0);

	printf("TEST 2 PRINT binary: %b\n", 1);
	_printf("TEST 2 PRINT binary: %b\n", 1);

	printf("TEST 3 PRINT binary: %b\n", 1024);
	_printf("TEST 3 PRINT binary: %b\n", 1024);

	printf("TEST 4 PRINT binary: %b\n", INT_MAX);
	_printf("TEST 4 PRINT binary: %b\n", INT_MAX);

	printf("TEST 5 PRINT binary: %b\n", INT_MIN);
	_printf("TEST 5 PRINT binary: %b\n", INT_MIN);

	printf("TEST 6 PRINT binary: %b\n", -98);
	_printf("TEST 6 PRINT binary: %b\n", -98);

	return (0);
}
