/**
 * *_memcpy - copies memory area
 * @dest: destination copy
 * @src: source copy
 * @n: number bytes copy
 * Return: destination *dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int count = 0;

	while (count < n)
	{
		dest[count] = src[count];
		++count;
	}
	return (dest);
}
