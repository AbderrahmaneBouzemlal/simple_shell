#include "main.h"
/**
 * my_strlen - calculate the length of an string
 * @str: A pointer to a string
 * Return: the length
 */
int my_strlen(char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}
