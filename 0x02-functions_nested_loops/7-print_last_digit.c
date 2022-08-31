#include "main.h"

/**
 * print_last_digit - prints the last digit
 *
 * @n: last digit
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
	int m;
	int last;

	m = n % 10;
	if (n >= 0)
		last = m;
	else
		last = -m;
	_putchar('0' + last);
	return (last);
}
