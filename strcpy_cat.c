#include "main.h"
/**
 * my_strcpy - copying from src to dest
 * @dest: ptr to a string
 * @src: ptr to a string
 * Return: a ptr to a string
 */
char *my_strcpy(char *dest, char *src)
{
	char *originalDest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (originalDest);
}
/**
 * my_strcat - concatenate src to dest
 * @dest: ptr to a string
 * @src: ptr to a string
 * Return: a ptr to a string
 */
char *my_strcat(char *dest, char *src)
{
	char *originalDest = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (originalDest);
}
