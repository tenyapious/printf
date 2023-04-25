#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - outputs a string after it has been properly formatted
 *
 * @format: inputs that determine how printf handles and returns the string
 *
 * Return: returns and prints a formatted string
 *
 */

int _printf(const char *format, ...)
{
    int i, j, k;
    char *str;
    char c;
    char *s;
    va_list ap;
    int args_len = 0;
    int format_len = 0;
    int num_output_char;

    va_start(ap, format);
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
    va_end(ap);

    num_output_char = format_len + args_len;

    str = malloc(sizeof(*str) * (num_output_char + 1));

    va_start(ap, format);
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

    va_end(ap);

    str[j] = '\0';

    write(STDOUT_FILENO, str, sizeof(char) * num_output_char);

    free(str);

    return (num_output_char);
}
