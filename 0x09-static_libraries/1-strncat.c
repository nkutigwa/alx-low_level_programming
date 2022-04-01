#include "holberton.h"

/**
 * *_strncat - concatenate two  strings and returns what evert index we need
 * @dest: pointer to a string
 * @src: pointer to the strign to concatenate
 * @n : interger number
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int length, count;
	int a = 0;

	while (dest[a])
		++a;
	length = a;

	for (count = 0; count < n && src[count] != '\0'; count++)
		dest[length + count] = src[count];
	dest[length + count] = '\0';

	return (dest);
}
