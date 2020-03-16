#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int _putchar(char c);
int _puts(char *str);
int (*get_formating(char *s))(void *);
int character(void *c);
int string(void *s);
int decimal(void *d);
int _printf(const char *format, ...);

typedef struct op
{
	char *format;
	int (*f)(void *data);
} format_op;

#endif