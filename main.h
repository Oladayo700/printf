#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/* Function prototype for custom _printf function */
int _printf(const char *format, ...);

/* Function prototype for the custom_printf_binary function */
int custom_printf_binary(const char *format, ...);

#endif /* MAIN_H */
