/**
 * *_strchr - locates a character in a string
 * @s: pointer to a string
 * @c: character with the n of index
 * Return:  pointer
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	int length;
	char *r = 0;

	while (s[i])
		++i;
	length = i;
	i = 0;

	for (; i <= length; i++)
	{
		if (s[i] ==  c)
		{
			r = &s[i];
			break;
		}
		else
			s = s + 1;
	}
	return (r);
}
