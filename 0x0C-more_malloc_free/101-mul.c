#include <stdlib.h>
#include "holberton.h"
/**
* printError - prints error message
* Return: nothing
**/
void printError(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}
/**
* digit_checker - checks if the passed arguements are valid
* @str: pointer to char
* Return: 0 if all chars are digits else -1
**/
int digit_checker(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printError();
			return (-1);
		}
	}
	return (0);
}
/**
* _strlen - calculates length of passed string
* @str: pointer to char
* Return: length of string
**/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
* _reallocate - reallocates memory if carry over if greater than 9
* @str: pointer to char
* @newSize: new size to allocate
* Return: pointer to newly allocated memory
**/
char *_reallocate(char *str, int newSize)
{
	char *newStr;

	newStr = malloc(newSize * sizeof(char *));
	if (newStr == NULL)
	{
		free(str);
		return (NULL);
	}
	return (newStr);
}
/**
* mulNums - multiply an array
* @str: array to be multiplied
* @n: multiplier
* @zeros: number of zeros to be added
* Return: array with result
**/
char *mulNums(char *str, char n, int zeros)
{
	char *res, *newRes;
	int i, k, mul, size, len, reSize;

	len = _strlen(str);
	size = reSize = len + zeros + 1;
	res = malloc(sizeof(char) * size);
	if (res == NULL)
	{
		printError();
		return (NULL);
	}
	size--;
	while (zeros > 0)
	{
		res[size] = '0';
		size--, zeros--;
	}
	k = 0;
	mul = 1;
	while (size > 0)
	{
		mul = ((str[len - 1] - '0') * (n - '0')) + k;
		res[size] = (mul % 10) + '0';
		k = mul / 10;
		size--, len--;
	}
	if (k >= 0 && k <= 9)
	{
		res[size] = k + '0';
		return (res);
	}
	else if (k > 9)
	{
		res[size] = (k % 10) + '0';
		newRes = _reallocate(res, reSize + 1);
		if (newRes == NULL)
			return (NULL);
		newRes[0] = (k / 10) + '0';
		for (i = 1; i < reSize + 1; i++)
			newRes[i] = res[i];
		free(res);
		return (newRes);
	}
	res[size] = '0';
	return (res);
}
/**
* addNums - add two arrays of digits
* @str1: array 1
* @str2: array2
* Return: pointer to char with sum
**/
char *addNums(char *str1, char *str2)
{
	char *add, *newAdd;
	int sum, k, len1, len2, size, reSize, i;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	size = reSize = len2 + 2;
	add = malloc(sizeof(char) * size);
	if (add == NULL)
	{
		free(str1);
		free(str2);
		printError();
		return (NULL);
	}
	size--, len2--, len1--;
	sum = k = 0;
	sum = (str1[len1] - '0') + k;
	add[size] = (sum % 10) + '0';
	k = sum / 10;
	size--, len1--;
	while (len2 >= 0)
	{
		if (len1 < 0)
			sum = (str2[len2] - '0') + k;
		else
			sum = (str1[len1] - '0') + (str2[len2] - '0') + k;
		add[size] = (sum % 10) + '0';
		k = sum / 10;
		size--, len1--, len2--;
	}
	if (k >= 0 && k <= 9)
	{
		add[size] = k + '0';
		return (add);
	}
	else if (k > 9)
	{
		add[size] = (k % 10) + '0';
		newAdd = _reallocate(add, reSize + 1);
		if (newAdd == NULL)
			return (NULL);
		newAdd[0] = (k / 10) + '0';
		for (i = 1; i < reSize + 1; i++)
			newAdd[i] = add[i];
		free(add);
		return (newAdd);
	}
	add[size] = '0';
	return (add);
}
/**
* printResult - prints result
* @result: resultant string
* Return: nothing
**/
void printResult(char *result)
{
	int i;

	if (result[0] != '0')
		_putchar(result[0]);

	for (i = 1; result[i] != '\0'; i++)
		_putchar(result[i]);
	_putchar('\n');
}
/**
* main - multiplies two positive numbers and prints result or error
* @argc: arguement count
* @argv: poinetr to arguements
* Return: 0 or exit with 98
**/
int main(int argc, char *argv[])
{
	int zero, len1, len2, counter;
	char *str1, *str2, *current, *temp, *sum;

	if (argc < 3 || argc > 3)
	{
		printError();
		exit(98);
	}
	if (digit_checker(argv[1]) == -1 || digit_checker(argv[2]) == -1)
		exit(98);
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	if (len2 > len1)
	{
		str1 = argv[2];
		str2 = argv[1];
		counter = len1 - 1;
	}
	else
	{
		str1 = argv[1];
		str2 = argv[2];
		counter = len2 - 1;
	}
	zero = 0;
	current = mulNums(str1, str2[counter], zero);
	if (current == NULL)
		exit(98);
	while (--counter >= 0)
	{
		temp = mulNums(str1, str2[counter], zero++);
		if (temp == NULL)
			exit(98);
		sum = addNums(current, temp);
		if (sum == NULL)
			exit(98);
		free(current);
		free(temp);
		current = sum;
	}
	printResult(sum);
	return (0);
}
