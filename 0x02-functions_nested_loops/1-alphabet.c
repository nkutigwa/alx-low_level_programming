#include "main.h"

/**
 * print_alphabet - function to print alphabet
 *
 * Return: no return
 *
 */
void print_alphabet(void)
{
	int i;

	for (i = 97; i <= 122; i++)
	{
		_putchar (i);
	}
	_putchar ('\n');
}
