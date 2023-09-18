#include"main.h"
#include <stdarg.h>
#include<string.h>
/**
 * _printf - print formated text
 * @format: format specifier
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, j = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	i{
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
