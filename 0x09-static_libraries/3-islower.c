#include <ctype.h>
#include "holberton.h"

/**
 * _islower - Entry Point
 * @c : is character int
 * Return: islower.
 */

int _islower(int c)
{

	char ch;
	int result = 0;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		if (ch == c)
			result = 1;
	}
	return (result);
}
