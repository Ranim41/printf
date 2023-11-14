#include "main.h"

/**
 * printf_S - Function that print string
 * @esra: string to be count
 * Return: int value
 */
int printf_S(char *esra)
{
	int i = 0;

	if (esra == NULL)
	return (write(1, "(null)", 6));
	while (*esra != '\0')
	{
		if (*esra < 32 || *esra >= 127)
		{
			write(1, "\\x", 2);
			i += printf_d_i((long)*esra, 16, 1);
		}
		else
		{
			printf_c((int)*esra);
			i++;
		}
		esra++;
	}
	return (i);
}
