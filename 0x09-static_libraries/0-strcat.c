#include "holberton.h"

/**
 * *_strcat - concatenate dos strings
 * @dest: pointer to a string
 * @src: pointer to the strign to concatenate
 *
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int length;
	int count = 0;
	int a = 0;

	while (dest[a])
		++a;
	length = a;

	while (count <= length && src[count] != '\0')
	{
		dest[length + count] = src[count];
		count++;
	}
	dest[length + count] = '\0';

	return (dest);
}
