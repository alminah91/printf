#include "main.h"
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
    int i, j = 0;
    int k;
    int divisor;

    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
        }
        else
        {
            i++;
            if (format[i] == 'c')
            {
                char c = (char)va_arg(args, int);
                _putchar(c);
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                int len = strlen(str);
                for (k = 0; k < len; k++)
                {
                    _putchar(str[k]);
                }
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                int num = va_arg(args, int);
                if (num < 0)
                {
                    _putchar('-');
                    num = -num;
                }
                divisor = 1;
                while (num / divisor > 9)
                {
                    divisor *= 10;
                }
                while (divisor != 0)
                {
                    int digit = num / divisor;
                    _putchar('0' + digit);
                    num %= divisor;
                    divisor /= 10;
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
            }
            else
            {
                /* Handle unsupported format specifier, if needed.*/
                /* You can choose to print an error message or ignore it.*/
            }
        }
        j++;
    }
    va_end(args);
    return j;
}
