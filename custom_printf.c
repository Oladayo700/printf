#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function with limited functionality.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...);
{
	va_list args;
	int printed_chars = 0;
	char c;
	char *s;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					putchar(c);
					printed_chars++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						putchar(*s);
						s++;
						printed_chars++;
					}
					break;
				case '%':
					putchar('%');
					printed_chars++;
					break;
				default:
					putchar('%');
					putchar(*format);
					printed_chars += 2;
					break;
				}
			}
			format++;
	}

	va_end(args);
	return (printed_chars);
}

/**
 * main - Entry point of the program.
 *
 * Description:
 * This function initializes variables and calls a custom_printf function to
 * format and print character, string, and number information. It then
 * displays the total characters printed and exits with a status code of 0.
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char c = 'X';
	char *s = "Hello, World!";
	int n = 12345;

	int chars_printed = _printf("Character: %c\nString: %s\nNumber: %d\n"
				"Percentage: %%\n", c, s, n);
	printf("Total characters printed: %d\n", chars_printed);

	return (0);
}
