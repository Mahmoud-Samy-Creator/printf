#include "main.h"

/**
 * print_char - A function return a string of a character
 * @args: argument list
 * Return: string
 */
int print_char(va_list args)
{
	putchar(va_arg(args, int));

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
