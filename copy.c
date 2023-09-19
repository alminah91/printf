#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'd' || *format == 'i') {
                int value = va_arg(args, int);
                printed_chars += printf("%d", value);
            } else {
                putchar('%');
		printed_chars++;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}
