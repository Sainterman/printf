#include "holberton.h"
/**
 * _strlen - Returns the length of a string.
 *
 * @s: address of first character in string.
 *
 * Return: integer length of a string.
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
int character(va_list c)
{
	int letra = va_arg(c, int);
	
	write(1, &letra, 1);

	return (1);
}

int string(va_list s)
{
	char *string = va_arg(s, char *);
	int size = _strlen(string);
	return(write(1, string, size));
}