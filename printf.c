#include "holberton.h"

int _printf(const char *format, ...)
{
	const char *recorrer; /* esto es un pointer a char que voy a utilizar para recorrer el string format */
	ssize_t bytes;	      /* el retorno seran los bytes impresos en standard output */

	va_list prints;
	va_start(prints, format);
	if (format == NULL)
		return (-1);

	for (recorrer = format; *recorrer != '\0'; recorrer++)
	{
		while (*recorrer != '%')
		{

			bytes += write(1, recorrer, 1);
			recorrer++;
			if (*recorrer == '\0')
				return ((int)bytes);
		}

		recorrer++;

		if (*recorrer == '%')
		{
			bytes += write(1, recorrer, 1);
		}
		else if (*recorrer == '\0')
		{
			bytes += write(1, "%", 1);
		}
		else if (*recorrer == 's' || *recorrer == 'c')
		{
			bytes += get_formating(recorrer)(prints);
		}
		else if (*recorrer == '\0' && (recorrer - 1) == format)
		{
			return (-1);
		}
	}
	va_end(prints);
	return ((int)bytes);
}