#include "holberton.h"

/**
 * *_strncpy - copy a string from another pointer
 * @dest: pointer to a string
 * @src: pointer to the strign to concatenate
 * @n: integer that represents number of bytes
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int count = 0;

	while (count < n && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	while (count < n)
	{
		dest[count] = '\0';
		count++;
	}
	return (dest);
}
