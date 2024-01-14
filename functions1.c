#include "main.h"

/**
 * print_zero -  A function to write "0" at stdout
 * @len: Statment length
 * @i: Statment counter
 * Return: 1
*/
void print_zero(int *i, int *len)
{
	write(1, "0", 1);
	(*len)++;
	(*i)++;
}

/**
 * print_max_int -  A function to write INT_MAX at stdout
 * @len: Statment length
 * @i: Statment counter
 * Return: 1
*/
int print_max_int(int *i, int *len)
{

	write(1, "-2147483648", 11);
	(*len) = (*len) + 11;
	(*i)++;
	return (1);
}

/**
 * print_zero_and_INTMAX - printing zero or INT_MAX to stdout
 * @len: Statment length
 * @i: Statment counter
 * @integer: Number to compare it's status
 * Return: 1
*/
int print_zero_and_INTMAX(int *i, int *len, int integer)
{
	if (integer == 0)
		return (print_zero(&(*i), &(*len)));

	if (integer == INT_MIN)
		return (print_max_int(&(*i), &(*len)));

	else
		return (0);
}

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

	if (integer == 0 || integer == INT_MIN)
		return (print_zero_and_INTMAX(&(*i), &(*len), integer));

	if (integer < 0)
		change_sign(&integer, &temp);

	/* Here we know the number digit len */
	number_len(&integer, &digit);
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
	string_reverse(&j, &k, string, str);
	string[j] = '\0';

	if (final < 0)
	{
		write(1, "-", 1);
		write(1, string, digit);
		(*i)++;
		(*len) = (*len) + 1 + digit;
		free_statments(string, str);
		return (1);
	}
	write(1, string, digit);
	(*i)++;
	(*len) += strlen(string);
	free_statments(string, str);
	return (1);
}

/**
 * print_unsigned_int - A function to print integers
 * @args: list of arguments
 * @i: pointer to counter
 * @len: pointer to length
 * Return: 1
 */
int print_unsigned_int(va_list args, int *i, int *len)
{
	int integer = va_arg(args, int);
	int k = 0, j = 0, digit = 0, temp = integer, final = integer;
	char *str, *string;

	if (integer == 0 || integer == INT_MIN)
		return (print_zero_and_INTMAX(&(*i), &(*len), integer));

	if (integer < 0)
		change_sign(&integer, &temp);

	number_len(&integer, &digit);
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
	string_reverse(&j, &k, string, str);
	string[j] = '\0';

	if (final < 0)
	{
		write(1, "-", 1);
		write(1, string, digit);
		(*i)++;
		(*len) = (*len) + 1 + digit;
		free_statments(string, str);
		return (1);
	}
	write(1, string, digit);
	(*i)++;
	(*len) += strlen(string);
	free_statments(string, str);
	return (1);
}
