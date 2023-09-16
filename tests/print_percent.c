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
	printf("TEST 0 PRINT %%\n");
	_printf("TEST 0 PRINT %%\n");

	printf("TEST 1 PRINT %%d\n");
	_printf("TEST 1 PRINT %%d\n");

	printf("TEST 2 PRINT %%%%\n");
	_printf("TEST 2 PRINT %%%%\n");

	return (0);
}
