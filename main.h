#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct dir{
	char cs;
	void(*f)();
} cs_t;

void _putcharc(char c);
void _putchar(va_list a);
void print_str(va_list a);


int _printf(const char *format, ...);

#endif
