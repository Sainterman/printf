#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int _putchar(char c);
int _puts(char *str);
int (*get_formating(const char *s))(va_list);
int character(va_list c);
int _strlen(char *s);
int string(va_list s);
int _printf(const char *format, ...);

typedef struct op
{
	char *format;
	int (*f)(void *data);
} format_op;

#endif