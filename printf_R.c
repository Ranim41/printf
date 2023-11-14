#include "main.h"

/**
 * printf_R - function that handle R
 *
 * @s: pointer to string
 *
 * Return: *s
 */

int printf_R(char *s)
{
	int i;
	char c, base;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			base = (c >= 'a') ? 'a' : 'A';
			s[i] = (c - base + 13) % 26 + base;
		}
	}
	return (write(1, s, _strlen(s)));
}
