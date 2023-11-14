#include "main.h"

/**
 * printf_p - function that handle the pointer
 * @ptr: pointer
 * Return: int value
 */

int printf_p(void *ptr)
{
	char buffer[64];
	int j = 0;
	int i;

	sprintf(buffer, "%p", ptr);

	for (i = 0; buffer[i] != '\0'; i++)
	{
		j += printf_c(buffer[i]);
	}

	return (i);
}
