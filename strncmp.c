#include "main.h"
/**
 * _strncmp - compares two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 * @n: The number of characters to be compared
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2
 */
int _strncmp(register const char *s1, register const char *s2,
		register size_t n)
{
	if (n == 0)
		return (0);
	do {
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *) --s2);
		if (*s1++ == 0)
			break;
	} while (--n != 0);
	return (0);
}
