#include <unistd.h>
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
	int i, j;
	char c;
	char *s;

	va_list args;

	va_start(args, format);

	for (i = 0, j = 0; format[i] != '\0'; i++, j++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					c = (char) va_arg(args, int);
					write(1, &c, 1);
					i += 2;
					j++;
					break;
				case 's':
					s = va_arg(args, char *);
					while (*s)
					{
						write(1, s++, 1);
						j++;
					}
					i += 2;
					break;
				case '%':
					i++;
					break;
			}
		}
		write(1, &format[i], 1);
	}

	va_end(args);

	return (j);
}
