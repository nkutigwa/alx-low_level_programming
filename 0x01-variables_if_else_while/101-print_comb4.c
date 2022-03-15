#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)

{
int digit1, digit2, digit3;

for (digit1 = 0; digit1 < 8; digit1++)
{

for (digit2 = digit1 + 1; digit2 < 9; digit2++)
{

putchar((digit1 % 10) + '0');
putchar((digit2 % 10) + '0');
putchar((digit3 % 10) + '0');

if (digit1 == 7 && digit2 == 8 && digit3 == 9)
continue;

putchar(',');
putchar(' ')'

}

}

}

putchar('\n');

return (0);

}

