#include "main.h"
/**
 * _strcat - concatenates two strings
 * @src: A string that will be appended
 * @dest: A string that will be appended to
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int len = 0, lend = 0, i;

	while (src[len] != '\0')
	{
		len++;
	}
	while (dest[lend] != '\0')
	{
		lend++;
	}
	for (i = 0; i < len; i++)
	{
		dest[lend + i] = src[i];
	}

	dest[lend + len] = '\0';

	return (dest);
}
