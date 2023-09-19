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
	if (integer == INT_MIN)
	{
		write(1, "-2147483648", 11);
		(*len) = (*len) + 11;
		(*i)++;
		return (1);
	}

	if (integer < 0)
	{
		integer = -integer;
		temp = -temp;
	}
	while (integer != 0)
	{
		integer /= 10;
		digit++;
	}
	integer = temp;
	str = malloc(digit + 1);
	string = malloc(digit + 1);
	for (k = 0 ; k < digit ; k++)
	{
		integer %= 10;
		temp /= 10;
		str[k] = integer + '0';
		integer = temp;
	}
	str[k] = '\0';
	while (k--)
	{
		string[j] = str[k];
		j++;
	}
	string[j] = '\0';

	if (final < 0)
	{
		write(1, "-", 1);
		write(1, string, digit);
		(*i)++;
		(*len) = (*len) + 1 + digit;
		return (1);
	}
	write(1, string, digit);
	(*i)++;
	(*len) += strlen(string);
	free(str);
	free(string);
	return (1);
}

/**
 * print_unsigned_int - A function to print unsigned integers
 * @args: list of arguments
 * @i: pointer to counter
 * @len: pointer to length
 * Return: 1
 */

unsigned long int print_int(va_list args, int *i, int *len)
{
	unsigned long int integer = va_arg(args, int);
	unsigned long int k = 0, j = 0;
	unsigned long int digit = 0, temp = integer, final = integer;
	char *str, *string;

	if (integer == 0)
	{
		write(1, "0", 1);
		(*len)++;
		(*i)++;
		return (1);
	}
	if (integer == INT_MIN)
	{
		write(1, "-2147483648", 11);
		(*len) = (*len) + 11;
		(*i)++;
		return (1);
	}

	if (integer < 0)
	{
		integer = -integer;
		temp = -temp;
	}
	while (integer != 0)
	{
		integer /= 10;
		digit++;
	}
	integer = temp;
	str = malloc(digit + 1);
	string = malloc(digit + 1);
	for (k = 0 ; k < digit ; k++)
	{
		integer %= 10;
		temp /= 10;
		str[k] = integer + '0';
		integer = temp;
	}
	str[k] = '\0';
	while (k--)
	{
		string[j] = str[k];
		j++;
	}
	string[j] = '\0';

	if (final < 0)
	{
		write(1, "-", 1);
		write(1, string, digit);
		(*i)++;
		(*len) = (*len) + 1 + digit;
		return (1);
	}
	write(1, string, digit);
	(*i)++;
	(*len) += strlen(string);
	free(str);
	free(string);
	return (1);
}
