#include "main.h"

/**
 * _isupper - checks for upper character
 *
 * @c: letter
 * Return: 1 if the letter is in uppercase and 0 otherwise
 */
int _isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	else
		return (0);
}
