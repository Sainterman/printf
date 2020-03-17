#include "holberton.h"

int _printf(const char *format, ...)
{
	const char *recorrer; /* esto es un pointer a char que voy a utilizar para recorrer el string format */
	ssize_t bytes; /* el retorno seran los bytes impresos en standard output */
	int (*formating)(va_list);
	char identifier;

	va_list prints;
	va_start(prints, format);

	for (recorrer = format; recorrer != '\0'; recorrer++)
	{
		while (*recorrer != '%')
		{
			bytes += write(1, recorrer, 1);
			recorrer++;
		}

		recorrer++;
		/* Aqui debe imprimir con el formato correcto */
		/* se debe pasar solo el caracter, al enviar el puntero recorrer esta enviando todo el string sobrante */
		/* primero hay que ver donde esta el char de formato. puede ser %     s y debe funcionar */
		identifier = *recorrer;
		formating = get_formating(&identifier); /* utilizando la funcion get_formating con el caracter de formato necesario */

		if (formating == NULL)
		{
			bytes += write(1, recorrer, 1);
		}
		else
		{
			bytes += formating(prints); /* utilizando la funcion donde apunta formating con el argumento siguiente */
		}
		
	}
	va_end(prints);
	return ((int)bytes);
}