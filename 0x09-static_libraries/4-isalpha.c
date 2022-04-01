/**
 * _isalpha - show an int by stdout c
 * @c: The character to print
 *
 * Return: On (success) 1
 */

int _isalpha(int c)
{

	int r = 0;
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (c == letter)
			r = 1;
	}
	for (letter = 'A'; letter <= 'Z'; letter++)
	{
		if (c == letter)
			r = 1;
	}

	return (r);
}
