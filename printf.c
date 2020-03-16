#include "holberton.h"

int _printf(const char *format, ...)
{
	const char *recorrer; /* esto es un pointer a char que voy a utilizar para recorrer el string format */
	unsigned int bytes; /* el retorno seran los bytes impresos en standard output */
	int (*formating)(void *);
	
	va_list prints;
	va_start(prints, format);

	for (recorrer = format; recorrer != '\0'; recorrer++)
	{
		while (*recorrer != '%')
		{
			bytes += write(2, recorrer, 1);
			recorrer++;
		}

		recorrer++;
		/* Aqui debe imprimir con el formato correcto */

		formating = get_formating(*recorrer); /* utilizando la funcion get_formating con el caracter de formato necesario */

		if (formating == NULL)
		{
			bytes += write(2, recorrer, 1);
		}

		bytes += formating(va_arg(prints, void *)); /* utilizando la funcion donde apunta formating con el argumento siguiente */
	}
}