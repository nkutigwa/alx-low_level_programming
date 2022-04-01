/**
 * *_strpbrk - searches string for any set of bytes
 * @s: pointer to a string
 * @accept: pointer to a string
 * Return: pointer
 */
char *_strstr(char *haystack, char *needle)
{
        int b;

        while (*haystack != '\n')
        {
                for (b = 0; needle[b] != '\0'; b++)
                {
                        if (*haystack == needle[b])
                        {
                                return (haystack);
                        }
                }
                haystack++;
        }
        return (0);
}
