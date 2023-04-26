#include <stdio.h>
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
	va_list ap;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			_putchar((char)va_arg(ap, int));
			i++;
			j++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(ap, char *);
			for (k = 0; s[k] != '\0';)
			{
				_putchar(s[k]);
				k++;
				j++;
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1 == '%'])
		{
			_putchar(format[i]);
			i++;
			j++;
		}
		else
		{
			_putchar(format[i]);
			j++;
		}
	}
	va_end(ap);
	return (j - 1);
}
