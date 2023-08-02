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
	char str[2500] = "";
	char temp[2] = "";
	int len = 0;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				strcat(str, print_char(args));
				len++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *string = print_str(args); 
				strcat(str, string);
				len += strlen(string);
				i++;
			}
			else if (format[i + 1] == '%')
			{
				strcat(str, "%");
				len++;
				i++;
			}
			else
			{
				temp[0] = format[i];
				temp[1] = '\0';
				strcat(str, temp);
				len++;
			}
		}
		else
		{
			temp[0] = format[i];
			temp[1] = '\0';
			strcat(str, temp);
			len++;
		}
	}
	va_end(args);
	write(1, str, strlen(str));
	return (len);
}
