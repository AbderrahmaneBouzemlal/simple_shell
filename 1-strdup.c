#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strdup - duplicate the string parameter
 * @str: A pointer to a string to be duplicated
 * Return: a pointer to a string
 */
char *_strdup(char *str)
{
	char *ptr;
	int i = 0;
	int size = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[size] != '\0')
	{
		size++;
	}
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	for (; i < size + 1; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}
