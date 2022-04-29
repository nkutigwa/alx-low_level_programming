#include <stdio.h>
#include "holberton.h"

/**
 * set_bit - Print out the binary representation of an unsigned long int
 * @n: The unsigned long int to print in binary
 * @index: The index at which to set the value to 1
 *
 * Return: 1 if it succeeds, -1 if it fails
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int revnum;
	unsigned long int num;
	unsigned long int count;
	unsigned long int oldn;

	revnum = count = num = 0;
	oldn = *n;
	if (index > 63)
		return (-1);
	while (count < 63)
	{
		revnum = revnum << 1;
		if (count == index)
			revnum += 1;
		else
			revnum += oldn & 1;
		count++;
		oldn = oldn >> 1;
	}
	while (count > 0)
	{
		num = num << 1;
		num += revnum & 1;
		revnum = revnum >> 1;
		count--;
	}
	*n = num;
	return (1);
}
