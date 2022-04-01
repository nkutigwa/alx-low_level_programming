/**
 * _strlen - show the lenght of a string
 * @s: pointe to  pass the array
 *
 * Return: none
 */

int _strlen(char *s)

{
	int a = 0;

	while (s[a])
		++a;

	return (a);
}
