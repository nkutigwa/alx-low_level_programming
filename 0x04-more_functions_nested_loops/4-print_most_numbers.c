#include "main.h"

/**
 * print_most_numbers - print from 0 to 9 without 2 and 4 then new line
 *
 * Return: void
 */
void print_most_numbers(void)
{
	int m;

	for (m = 0; m < 10; m++)
	{
		if ((m == 2) || (m == 4))
			continue;
		_putchar('0' + m);
	}
	_putchar('\n');
}
