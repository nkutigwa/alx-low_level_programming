#include "main.h"
#include <ctype.h>

/**
 * _islower - if the character is lowercase
 * @c:  is the int that will use for the argument of the function
 * Return: 1 if lowercase character 0 if not
 */
int _islower(int c)
{
	if (islower(c))
		return (1);
	return (0);
}
