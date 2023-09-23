#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * custom_printf_binary - Custom printf function
 * that supports the 'b' specifier
 * @format: Format string
 * @...: Variable number of arguments
 *
 * This function handles the custom 'b' specifier to convert an
 * an unsigned int argument to binary.
 *
 * Return: Number of characters printed.
 */
int custom_printf_binary(const char *format, ...)
{
	va_list args;
	int written_chars = 0;

	va_start(args, format);


	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int value = va_arg(args, unsigned int);
			char binary[32];
			int i = 0;

			int bit;

			for (bit = 31; bit >= 0; --bit)
			{
				binary[i++] = ((value >> bit) & 1) ? '1' : '0';
			}
			binary[i] = '\0';

			written_chars += printf("%s", binary);

			format += 2;
		}
		else
		{
			putchar(*format);
			++written_chars;
			++format;
		}
	}

	va_end(args);
	return (written_chars);
}
