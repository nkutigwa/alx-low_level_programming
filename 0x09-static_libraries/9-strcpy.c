#include "holberton.h"

/**
 * *_strcpy - copy a string from another pointer
 * @dest: pointer to a string
 * @src: pointer to the strign to concatenate
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;
	int length;

	while (src[count])
		++count;
	length = count;

	count = 0;
	while (count <= length)
	{
		dest[count] = src[count];
		count++;
	}
	return (dest);
}

