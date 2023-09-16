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
	printf("HI THERE\n");
	_printf("HI THERE\n");

	printf("TEST PRINT CHAR: %c\n", 'H');
	_printf("TEST PRINT CHAR: %c\n", 'H');

	printf("TEST PRINT STRING: %s\n", "Hello");
	printf("TEST PRINT STRING: %s\n", "Hello");

	return (0);
}
