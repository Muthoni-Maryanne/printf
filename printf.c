#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - custom printf function
 * @format: pointer that holds format string
 * 
 * Return: int
*/
int _printf(const char *format, ...)
{
    int num = 0;
    va_list list_args;

    if (format == NULL)
    {
        return (-1);
    }

    va_start(list_args, format);

    while(*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            num++;
        }
        else
        {
            format++;
            if (*format == '\0')
            {
                break;
            }

            if (*format == 'c')
            {
                char c = va_arg(list_args, int);
                write(1, &c, 1);
                num++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(list_args, char*);
                int length = 0;

                while (str[length] != '\0')
                {
                    length++;
                }

                write(1, str, length);
                num += length;
            }
            else if (*format == '%')
            {
                write(1, format, 1);
                num++;
            }
        }
        format++;
    }
    va_end(list_args);

    return num;
}