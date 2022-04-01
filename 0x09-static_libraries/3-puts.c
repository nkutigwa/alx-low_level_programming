#include "holberton.h"
/**
 * _strlen - show the lenght of a string
 * @s: pointe to  pass the array
 *
 * Return: a
 */
int _strlen(char *s)
{
	int a = 0;

	while (s[a])
		++a;
	return (a);
}

/**
 * _puts - put a string
 * @str: pointer to the argument string
 *
 * Return: none
 */
void _puts(char *str)
{

	int count;

	for (count = 0; count < _strlen(str); count++)
		_putchar(str[count]);
	_putchar('\n');
}
