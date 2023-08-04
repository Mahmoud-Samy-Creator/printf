#include "main.h"

/**
 * print_char - A function return a string of a character
 * @args: argument list
 * @i: pointer to counter
 * Return: string
 */
int print_char(va_list args, int *i)
{
	char temp[2] = "";

	temp[0] = va_arg(args, int);
	temp[1] = '\0';
	write(1, temp, 1);
	(*i)++;
	return (1);
}

/**
 * print_str - A function return a string
 * @args: argument list
 * @i: pointer to counter
 * Return: string
 */
int print_str(va_list args, int *i)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*i)++;
		return (6);
	}

	write(1, str, strlen(str));
	(*i)++;
	return (strlen(str));
}

/**
 * print_statments - A function for printing a statment
 * @format: a char to print
 * @len: pointer to length
 * Return:1
 */

int print_statments(char format, int *len)
{
	char temp[2] = "";

	temp[0] = format;
	temp[1] = '\0';
	write(1, temp, 1);
	(*len)++;
	return (1);
}

/**
 * print_percent - A function to write %
 * @i: pointer to counter
 * Return: 1
*/

int print_percent(int *i)
{
	write(1, "%", 1);
	(*i)++;
	return (1);
}


