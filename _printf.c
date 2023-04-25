#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_size - calculate the length of output string
 * @format: input string
 * @ap: argument list
 *
 * Return: size of output string
 */
int get_size(const char *format, va_list ap)
{
	int i, k;

	char __attribute__ ((unused)) c;
	char *s;
	int args_len = 0;
	int format_len = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = (char)va_arg(ap, int);
				args_len++;
				format_len -= 2;
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(ap, char *);
				for (k = 0; s[k] != '\0';)
				{
					k++;
					args_len++;
				}
				format_len -= 2;
			}
		}
		format_len++;
	}
	return (args_len + format_len);
}


/**
 * output_str - combine input string and arguments
 * @str: allocated memory for output string
 * @format: input string
 * @ap: argument list
 *
 */

void output_str(char *str, const char *format, va_list ap)
{
	int i, j, k;
	char c;
	char *s;

	for (i = 0, j = 0; format[i] != '\0';)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = (char)va_arg(ap, int);
				str[j] = c;
				j++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(ap, char *);
				for (k = 0; s[k] != '\0';)
				{
					str[j] = s[k];
					j++;
					k++;
				}
				i++;
			}
			else if (format[i + 1] == '%')
			{
				str[j] = '%';
				j++;
				i++;
			}
			else
			{
				str[j] = format[i];
				j++;
			}
		}
		else
		{
			str[j] = format[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

/**
 * _printf - print formatted string
 * @format: input string
 *
 * Return: length of formatted string
 */
int _printf(const char *format, ...)
{
	char *str;
	va_list ap;
	int num_output_char;

	va_start(ap, format);
	num_output_char = get_size(format, ap);

	/**
	va_end(ap);

	str = malloc(sizeof(*str) * (num_output_char + 1));
	if (!str)
	{
		return (0);
	}

	va_start(ap, format);

	*/
	output_str(str, format, ap);
	va_end(ap);

	write(STDOUT_FILENO, str, sizeof(char) * num_output_char);

	/* free(str); */

	return (num_output_char);
}
