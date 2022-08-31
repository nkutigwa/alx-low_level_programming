#include "main.h"

/**
 * print_numbers - print from 0 to 9 the a new line
 *
 * Return: no value
 */
void print_numbers(void)
{
	int n;

	for (n = 0; n < 10; n++)
		_putchar('0' + n);
	_putchar('\n');
}
