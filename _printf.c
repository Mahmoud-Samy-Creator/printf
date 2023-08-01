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
	char str[5000] = "", temp[2] = "";
	size_t len = 0;

	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}

	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}

			if (format[i + 1] == 'c')
			{
				char *ch = print_char(args);

				if (strlen(ch) == 0)
					len++;

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
	write(1, str, strlen(str));
	return (strlen(str) + len);
}
