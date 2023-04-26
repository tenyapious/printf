#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - print formatted string
 * @format: input string
 *
 * Return: length of formatted string
 */
int _printf(const char *format, ...)
{
	int i, j = 0, k;
	char *s;
	char c;
	va_list ap;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = (char)va_arg(ap, int);
			write(1, &c, 1);
			i++;
			j++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(ap, char *);
			for (k = 0; s[k] != '\0';)
			{
				write(1, &(s[k]), 1);
				k++;
				j++;
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1 == '%'])
		{
			write(1, &(format[i]), 1);
			i++;
			j++;
		}
		else
		{
			write(1, &(format[i]), 1);
			j++;
		}
	}
	va_end(ap);
	return (j - 1);
}
