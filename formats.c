#include "holberton.h"

int character(void *c)
{
	char *letra = c;
	unsigned int b = write(2, *letra, 1);

	return (b);
}

int string(void *s)
{
	char *string = s;
	int i = 0;

	while (string[i] != '\0')
	{
		write(2, string[i], 1);
		i++;
	}
}