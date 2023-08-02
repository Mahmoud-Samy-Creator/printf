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
    size_t len = 0; // To keep track of the total length
    char temp[2] = "";

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
            {
                char c = (char) va_arg(args, int);
                temp[0] = c;
                temp[1] = '\0';
                write(1, temp, 1);
                len += 1;
                i++;
            }
            else if (format[i + 1] == 's')
            {
                const char *s = va_arg(args, const char *);
                if (s != NULL)
                {
                    len += strlen(s);
                    write(1, s, strlen(s)); // Print the string directly
                }
                i++;
            }
            else if (format[i + 1] == '%')
            {
                temp[0] = format[i];
                temp[1] = '\0';
                write(1, temp, 1);
                len += 1;
                i++;
            }
            else
            {
                temp[0] = format[i];
                temp[1] = '\0';
                write(1, temp, 1);
                len += 1;
            }
        }
        else
        {
            temp[0] = format[i];
            temp[1] = '\0';
            write(1, temp, 1);
            len += 1;
        }
    }
    va_end(args);
    return (int)len; // Return the total number of characters printed
}

