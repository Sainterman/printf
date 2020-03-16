#include "holberton.h"

int (*get_formating(char *s))(void *)
{
	format_op ops[] = {
		{"c", character},
		{"s", string},
		{"d", decimal},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].format != NULL)
	{
		if (strcmp(ops[i].format, s) == 0)
		{
			break;
		}
		i++;
	}
	return (ops[i].f);
}