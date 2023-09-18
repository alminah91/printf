#include"main.h"
#include <stdarg.h>
#include<string.h>

int _printf(const char *format, ...)
{
        int i, j = 0;
        va_list args;
        va_start(args, format);

        for(i = 0;format[i] != '\0'; i++)
        {
                if (format[i] != '%')
                {
                        _putchar(format[i]);
                }
                else if (format[i + 1] == 'c')
                {
                        _putchar(va_arg(args, int));
                        i++;
                }
                else if (format[i + 1] == '%')
                {
                        _putchar('%');
                }
                j += 1;

        }
        va_end(args);
        return (j);
}
