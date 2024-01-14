#include "main.h"

/**
 * print_char - A function return a string of a character
 * @args: argument list
 * @i: pointer to counter
 * @len: pointer to length
 * Return: string
 */
void print_char(va_list args, int *i, int *len)
{
	_putchar(va_arg(args, int));
	(*i)++;
	(*len)++;
}

/**
 * print_str - A function return a string
 * @args: argument list
 * @i: pointer to counter
 * @len: pointer to length
 * Return: string
 */
int print_str(va_list args, int *i, int *len)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*i)++;
		(*len) += 6;
		return (1);
	}

	write(1, str, strlen(str));
	(*i)++;
	(*len) += strlen(str);
	return (1);
}

/**
 * print_statments - A function for printing a statment
 * @format: a char to print
 * @len: pointer to length
 * Return:1
 */
void print_statments(char format, int *len)
{
	char temp[2] = "";

	temp[0] = format;
	temp[1] = '\0';
	write(1, temp, 1);
	(*len)++;
}

/**
 * print_percent - A function to write %
 * @i: pointer to counter
 * @len: pointer to length
 * Return: 1
*/
void print_percent(int *i, int *len)
{
	_putchar('%');
	(*i)++;
	(*len)++;
}


