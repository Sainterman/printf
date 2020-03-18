#include "holberton.h"

int (*get_formating(const char *s))(va_list list)
{
	format_op ops[] = {
		{"c", character},
		{"s", string},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].format != NULL)
	{
		if (*s == *ops[i].format)
			return (ops[i].f);
		i++;
	}
	exit(1);
}