#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
	}
	i++;

	return (NULL);
}
