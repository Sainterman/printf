#include "holberton.h"

int _printf(const char *format, ...)
{
	const char *recorrer; /* esto es un pointer a char que voy a utilizar para recorrer el string format */
	ssize_t bytes; /* el retorno seran los bytes impresos en standard output */
	char identifier;

	va_list prints;
	va_start(prints, format);
    	if (format == NULL)
        	return (-1);
	for (recorrer = format; recorrer != '\0'; recorrer++)
	{
		while (*recorrer != '%')
		{
			bytes += write(1, recorrer, 1);
			recorrer++;
		}

		recorrer++;
		identifier = *recorrer;
		if (identifier == '%')
			bytes += write(1, &identifier, 1);
		else if (identifier == '\0')
		    	bytes += write(1, "%", 1);
		else if (identifier == 's' || identifier == 'c')
			bytes += get_formating(&identifier)(prints);
		else if (*recorrer == '\0' && (recorrer - 1) == format)
		{
			return (-1);
		}
		
	}
	va_end(prints);
	return ((int)bytes);
}