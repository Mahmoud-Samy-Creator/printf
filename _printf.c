#include "main.h"

/**
 * _printf - A function for printing
 * @format: format string
 * Return: string
 */
char *printing(char *format, va_list args)
{
	size_t i = 0;
	char *str = malloc(strlen(format));
	char temp[2] = "";

	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				strcat(str, print_char(args));
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
	return (str);
}
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;
	char string[strlen(format)];

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0 ; format[i] ; i++)
		string[i] = format[i];

	char *str = printing(string, args);

	va_end(args);
	write(1, str, strlen(str));
	return (strlen(str));
}
