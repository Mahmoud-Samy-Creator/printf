#include "main.h"

/**
 * print_int - A function to print integers
 * @args: list of arguments
 * @i: pointer to counter
 * @len: pointer to length
 * Return: 1
 */

int print_int(va_list args, int *i, int *len)
{
	int integer = va_arg(args, int);
	int k = 0, j = 0, digit = 0, temp = integer, final = integer;
	char *str, *string;

	if (integer == 0)
	{
		write(1, "0", 1);
		(*len)++;
		(*i)++;
		return (1);
	}

	if (integer < 0)
	{
		integer *= (-1);
		temp *= (-1);
	}
	while (integer != 0)
	{
		integer /= 10;
		digit++;
	}
	integer = temp;
	str = malloc(digit);
	string = malloc(digit);
	for (k = 0 ; k < digit ; k++)
	{
		integer %= 10;
		temp /= 10;
		str[k] = integer + 48;
		integer = temp;
	}

	while (k--)
	{
		string[j] = str[k];
		j++;
	}

	if (final < 0)
	{
		write(1, "-", 1);
		write(1, string, strlen(string));
		(*i)++;
		(*len) = (*len) + 1 + strlen(string);
		return (1);
	}
	write(1, string, strlen(string));
	(*i)++;
	(*len) += strlen(string);
	free(str);
	free(string);
	return (1);
}
