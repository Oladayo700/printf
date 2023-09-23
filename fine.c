#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* handle_conv - handle conversion
* @format: string
* @...: number of arguments
*/

void handle_conv(const char *format, ...)
{
va_list args;
int i = 0;

va_start(args, format);


while (format[i] != '\0')
{
if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
{
int value = va_arg(args, int);

printf("%d", value);
i += 2;
}
else
{
putchar(format[i]);
i++;
}
}

va_end(args);
}

