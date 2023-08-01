#include "main.h"

/**
 * print_char - A function return a string of a character
 * @args: argument list
 * Return: string
 */
char *print_char(va_list args)
{
	char *ch = malloc(1);

	if (ch == NULL)
		return (NULL);

	ch[0] = va_arg(args, int);

	return (ch);
}

/**
 * print_str - A function return a string
 * @args: argument list
 * Return: string
 */
char *print_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		return ("(null)");

	return (str);
}
