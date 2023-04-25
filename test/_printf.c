#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
    int i, j, k;
    char str[100];
    va_list ap;
    char c;
    char *s;

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

    write(STDOUT_FILENO, str, sizeof(char) * strlen(str));

    return (0);
}
