#include <stdlib.h>

/**
 * _abs - show an int by stdout c
 * @n: The character to print
 *
 * Return: On (success) 1
 */

int _abs(int n)
{
	int res;

	res = abs(n);
	if (res  < 0)
		res = res * -1;
	return (res);
}
