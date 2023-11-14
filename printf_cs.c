#include "main.h"
/**
 * _printf - Function that produces output according to a format
 * @format: variable
 * Return: int value
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list printf;

	va_start(printf, format);
	if (format == NULL)
	return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (format[0] == '%' && format[1] == '\0')
			return (-1);
			i += esra_format(*(++format), printf);
		}
		else
		i += write(1, format, 1);
		++format;
	}
	va_end(printf);
	return (i);
}

/**
 * printf_str - Function that print string
 * @atika: string to be count
 * Return: int value
 */
int printf_str(char *atika)
{
	if (atika == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		return (write(1, atika, _strlen(atika)));
	}
}


/**
 * printf_c -  Function that print character
 * @c: variable
 * Return: int value
 */

int printf_c(char c)
{
	return (write(1, &c, 1));
}

/**
 * printf_d_i - function that print an integer
 * @num: variable
 * @base: variable
 * @upper: variable
 * Return: int value
 */

int printf_d_i(long num, int base, int upper)
{
	int i = 0;
	char *ranim;

	if (upper)
	ranim = "0123456789ABCDEF";
	else
	ranim = "0123456789abcdef";

	if (num < 0)
	{
		write(1, "-", 1);
		return (printf_d_i(-num, base, upper) + 1);
	}
	else if (num < base)
	return (printf_c(ranim[num]));
	else
	{
		i += printf_d_i(num / base, base, upper);
		return (i + printf_d_i(num % base, base, upper));
	}
}

/**
 * esra_format - function that produce format
 * @sps: variable
 * @printf: va_list
 * Return: int value
 */

int esra_format(char sps, va_list printf)
{
	int i;

	i = 0;

		if (sps == 'c')
			i += printf_c(va_arg(printf, int));
		else if (sps == 's')
			i += printf_str(va_arg(printf, char *));
		else if (sps == '%')
			i += write(1, "%", 1);
		else if (sps == 'd' || sps == 'i')
			i += printf_d_i((long)va_arg(printf, int), 10, 0);
		else if (sps == 'x')
			i += printf_d_i((long)va_arg(printf, unsigned int), 16, 0);
		else if (sps == 'u')
			i += printf_d_i((long)va_arg(printf, unsigned int), 10, 0);
		else if (sps == 'o')
			i += printf_d_i((long)va_arg(printf, unsigned int), 8, 0);
		else if (sps == 'X')
			i += printf_d_i((long)va_arg(printf, unsigned int), 16, 1);
		else if (sps == 'b')
			i += printf_d_i((long)va_arg(printf, unsigned int), 2, 0);
		else if (sps == 'S')
			i += printf_S(va_arg(printf, char *));
		else if (sps == 'p')
			i += printf_p(va_arg(printf, void *));
		else if (sps == 'R')
			i += printf_R(va_arg(printf, char *));
		else if (sps == 'r')
			i += printf_rev(va_arg(printf, char *));
		else
			i += write(1, &sps, 1);
	return (i);
}
