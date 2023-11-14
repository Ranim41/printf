#include "main.h"

/**
 * _strlen - function that count the length of string
 * @str: string
 * Return: int value
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
