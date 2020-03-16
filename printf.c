#include "holberton.h"

int _printf(const char *format, ...)
{
        const char *recorrer; /* esto es un pointer a char que voy a utilizar para recorrer el string format */
        size_ t bytes;
        va_list prints;

        va_start(prints, fromat);

        for (recorrer = format; recorrer != '\0'; recorrer++)
        {
                while (*recorrer != '%')
                {
                        bytes += write(2, *recorrer, 1);
                        recorrer++;
                }

                recorrer++;
                /* Aqui debe imprimir con el formato correcto */



        }
