#include "main.h"

/**
 * times_table - prints the 9 times table starting from 0
 *
 * Return: nothing
 */
void times_table(void)
{
	int u;
	int v;
	int uv;

	for (u = 0; u < 10; u++)
	{
		for (v = 0; v < 10; v++)
		{
			uv = u * v;
			if (v == 0)
				_putchar('0' + uv);
			else if (uv >= 10)
			{
				_putchar(' ');
				_putchar('0' + (uv / 10));
				_putchar('0' + (uv % 10));
			}
			else
			{
				_putchar(' ');
				_putchar(' ');
				_putchar(uv + '0');
			}
			if (v != 9)
				_putchar(',');
		}
		_putchar('\n');
	}
}
