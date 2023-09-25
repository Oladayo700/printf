#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

/* Function prototype for custom _printf function */
int _printf(const char *format, ...);

/* Function prototype for the custom_printf_binary function */
int custom_printf_binary(const char *format, ...);
/**
 * handle_conv - Custom printf-like function for 'd' and 'i'
 * @format: The format string
 * @...: Variable number of arguments
 */
void handle_conv(const char *format, ...);
#endif /* MAIN_H */
