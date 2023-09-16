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

	printf("TEST 1 PRINT hex: %x\n", 255);
	_printf("TEST 1 PRINT hex: %x\n", 255);

	printf("TEST 2 PRINT hex: %X\n", 255);
	_printf("TEST 2 PRINT hex: %X\n", 255);

	printf("TEST 3 PRINT octal: %o\n", 255);
	_printf("TEST 3 PRINT octal: %o\n", 255);

	printf("TEST 4 PRINT unsigned: %u\n", 255);
	_printf("TEST 4 PRINT unsigned: %u\n", 255);

	return (0);
}
