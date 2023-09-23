#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Helper function to print a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed (1).
 */
static int print_char(int c)
{
	putchar(c);
	return (1);
}

/**
 * print_string - Helper function to print a string.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
static int print_string(char *s)
{
	int printed_chars = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		putchar(*s);
		s++;
		printed_chars++;
	}

	return (printed_chars);
}

/**
 * _printf - Custom printf function with limited functionality.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			printed_chars += print_char(*format);
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += print_char(va_arg(args, int));
					break;
				case 's':
					printed_chars += print_string(va_arg(args, char *));
					break;
				case '%':
					printed_chars += print_char('%');
					break;
				default:
					printed_chars += print_char('%');
					printed_chars += print_char(*format);
					break;
			}
		}
		format++;
	}

	va_end(args);
	return (printed_chars);
}
