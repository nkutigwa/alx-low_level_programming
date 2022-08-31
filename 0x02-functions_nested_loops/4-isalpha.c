#include "main.h"
#include <ctype.h>

/**
 * _isalpha - if the character is alphabet
 * @c:  is the int that will use for the argument of the function
 * Return: 1 if lowercase or uppercase character 0 if not
 */
int _isalpha(int c)
{
	if (islower(c) || isupper(c))
		return (1);
	return (0);
}
