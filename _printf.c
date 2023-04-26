#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



void _putcharc(char c)
{
	write(1, &c, 1);
}

void _putchar(va_list params)
{
	char c;

	c = va_arg(params, int);
	write(1, &c, 1);
}

/* handle strings */
void printstr(va_list params)
{
	char *c;
	c = va_arg(params, char *);
	
	/* loop and handle nullbyte */
	while (*c != '\0')
	{
		_putcharc(*c++);
	}
}


/* handle integers */
void print_int();
{
}



/* main _printf function */
int _printf(const char *format, ...)
{
	va_list params;
	int i = 0;
	int j = 0;
	int counter = 0;

	/* pass flags as a multidimensional array to loop through va */
	cs_t dir = [] = {
		{'c', _putchar},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int}
	};


	/* check for NULL */
	if (format == NULL)
		return (0);

	/* loop through format */
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (j < 4)
			{
				if (format[i + 1] == dir[j].cs && format[i + 1] != '%')
				{
					dir[j].f(a);
					i++;
				}
				j++;
			}
			i++;
			_putcharc(format[1]);
		}
		else
			_putcharc(format[1]);

		counter++;
		i++;
	}
	return (counter);
}
