/**
 * _isdigit - verificate if is a digit the parameter
 *@c: int with a character
 *
 * Return: 1 on success
 */

int _isdigit(int c)
{
	int res = 0;
	int num;

	for (num = 48; num <= 57; num++)
	{
		if (num == c)
			res = 1;
	}
	return (res);
}
