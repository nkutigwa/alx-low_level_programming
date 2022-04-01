/**
 * *_memset - memory with a constant byte
 * @s: array memory
 * @b: constant byte
 * @n: memory length
 * Return: array *s
 */
char *_memset(char *s, char b, unsigned int n)
{
	while (n--)
		s[n] = b;
	return (s);
}
