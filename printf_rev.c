#include "main.h"

/**
 * printf_rev - function that reverse string
 * @str: string
 * Return: int value
 */

int printf_rev(char *str)
{
	int len = 0;
	int i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = _strlen(str);
	for (i = len - 1; i >= 0 ; i--)
	{
		printf_c((int)str[i]);
	}
	return (len);
}
