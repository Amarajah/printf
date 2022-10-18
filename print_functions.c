#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */

int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += putchar(ch);
	while (pad++ < params->width)
		sum += putchar(pad_char);
	if (!params->minus_flag)
		sum += putchar(ch);
	return (sum);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (putchar('%'));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */

int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += putchar(*str++);

		else
			sum += puts(str);
	}
	while (j++ < params->width)
		sum += putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += putchar(*str++);
	else
		sum += puts(str);
	}
	return (sum);
}
