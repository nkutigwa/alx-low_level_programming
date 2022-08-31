#include "main.h"

/**
 * _abs - absolute value of a number
 * @n: number
 * Return: positive number
 */
int _abs(int n)
{
	if (n > 0)
	{
		return (n);
	}
	else if (n == 0)
	{
		return (0);
	}
	else
	{
		return (-n);
	}
}
