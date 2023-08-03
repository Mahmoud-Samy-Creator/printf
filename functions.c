#include "main.h"

/**
 * print_char - A function return a string of a character
 * @args: argument list
 * Return: string
 */
int print_char(va_list args, int *i)
{
	char temp[2] = "";

	temp[0] = va_arg(args, int);
	temp[1] = '\0';
	write(1, temp, 1);
	i++;
	return (1);
}

/**
 * print_str - A function return a string
 * @args: argument list
 * Return: string
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	write(1, str, strlen(str));

	return (strlen(str));
}

/**
 * print_statments - A function for printing a statment
 * @format: a char to print
 * Return:1
 */

int print_statments(char format)
{
	char temp[2] = "";

	temp[0] = format;
	temp[1] = '\0';
	write(1, temp, 1);
	return (1);
}
