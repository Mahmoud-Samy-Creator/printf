#include "main.h"

/**
 * _printf - A function for printing
 * @format: format string
 * Return: string
 */

int _printf(const char *format, ...)
{
	int i = 0, len = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				len += print_char(args, &i);

			else if (format[i + 1] == '%')
				print_percent(&i, &len);

			else if (format[i + 1] == 's')
				len += print_str(args, &i);

			else
				print_statments(format[i], &len);
		}
		else
			print_statments(format[i], &len);
	}
	va_end(args);
	return (len);
}
