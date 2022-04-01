#include "holberton.h"

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: value
 */
int _strcmp(char *s1, char *s2)
{
	int count = 0;
	int value = 0;

	while (s1[count] != '\0')
	{
		if (s1[count] > s2[count])
		{
			return (s1[count] - s2[count]);
		}
		else if (s1[count] < s2[count])
		{
			return (s1[count] - s2[count]);
		}
		count++;
	}
	return (value);
}
