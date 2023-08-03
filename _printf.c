#include "main.h"

/**
 * _printf - A function for printing
 * @format: format string
 * Return: string
 */

int _printf(const char *format, ...)
{
	size_t i = 0;
	int len = 0;
	va_list args;
	char temp[2] = "";

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i + 1] == 'c')
				len += print_char(args);

			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				len++;
			}
			else if (format[i + 1] == 's')
				len += print_str(args);

			else
			{
				temp[0] = format[i];
				temp[1] = '\0';
				write(1, temp, 1);
				len++;
			}
		}
		else
			len += print_statments(format[i]);
	}
	va_end(args);
	return (len);
}
