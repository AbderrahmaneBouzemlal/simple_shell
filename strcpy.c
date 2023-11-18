#include <stdio.h>
#include "main.h"
/**
 * _strcpy - copies the string pointed to by src
 * @dest: The destination of the copy
 * @src: pointing to the string that should copied from
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int length = 0;

	while (src[length] != '\0')
	{
		length++;
	}
	for (i = 0; i <= length; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
