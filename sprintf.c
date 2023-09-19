#include "main.h"
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
    int i, j = 0;
    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
        }
        else if (format[i + 1] == 'c')
        {
            char c = (char)va_arg(args, int);
            _putchar(c);
            i++;
        }
        else if (format[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            int len = strlen(str);
            int k;
            for (k = 0; k < len; k++)
            {
                _putchar(str[k]);
            }
            i++;
        }
        else if (format[i + 1] == '%')
        {
            _putchar('%');
            i++;
        }
        j++;
    }
    va_end(args);
    return j;
}
