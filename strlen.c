#include "main.h"
#include <stdio.h>
/**
 * _strlen - compute the length of a string
 * @s: The string we need to measure
 * Return: the length of a string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
