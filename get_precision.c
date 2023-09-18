#include "main.h"
/**
 * get_precision - Extracts the precision for printing
 * @format: The format string
 * @index: Pointer to the current position in the format string
 * @args: The va_list of arguments
 *
 * Return: The precision value or -1 if not specified
 */
int get_precision(const char *format, int *index, va_list args)
{
	int currIndex = *index + 1;
	int precision = -1;

	if (format[currIndex] != '.')
		return (precision);

	precision = 0;

	currIndex++;

	while (format[currIndex] != '\0')
	{
		if (is_digit(format[currIndex]))
		{
			precision *= 10;
			 precision += format[currIndex] - '0';
		}
		else if (format[currIndex] == '*')
		{
			currIndex++;
			precision = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}

		currIndex++;
	}

	*index = currIndex - 1;

	return (precision);
}
