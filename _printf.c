#include "main.h"

/**
 * _printf - A function for printing
 * @format: format string
 * Return: string
 */

int _printf(const char *format, ...)
{
	size_t i = 0;
	va_list args;
	char *ch = malloc(2);
	char str[2500] = "", temp[2] = "";

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ch = print_char(args);
				strcat(str, ch);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				strcat(str, print_str(args));
				i++;
			}
			else if (format[i + 1] == '%')
			{
				strcat(str, "%");
				i++;
			}
			else
			{
				temp[0] = format[i];
				temp[1] = '\0';
				strcat(str, temp);
			}
		}
		else
		{
			temp[0] = format[i];
			temp[1] = '\0';
			strcat(str, temp);
		}
	}
	va_end(args);
	free(ch);
	write(1, str, strlen(str));
	return (strlen(str));
}
