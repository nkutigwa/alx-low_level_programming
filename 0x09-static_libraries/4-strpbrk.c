/**
 * *_strpbrk - searches string for any set of bytes
 * @s: pointer to a string
 * @accept: pointer to a string
 * Return: pointer
 */
char *_strpbrk(char *s, char *accept)
{
	int b;

	while (*s)
	{
		for (b = 0; accept[b] != '\0'; b++)
		{
			if (*s == accept[b])
			{
				return (s);
			}
		}
		s++;
	}
	return (0);
}
