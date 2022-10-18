#include "main.h"

/**
 * _printf - prints string in a specific format
 * @format: string to print (char *)
 * @...: unknown variadic parameters
 * Return: number of printed character
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking NULL character*/
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
}
