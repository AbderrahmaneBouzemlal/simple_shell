#include "main.h"
/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory, wvim hich contains a copy of the string given as a parameter.
 * @s: The string to be copied
 * Return: A pointer to a string
 */
char *_strdup(const char *s)
{
	size_t len = _strlen(s) + 1;
	void *new = malloc(len);

	if (new == NULL)
		return (NULL);
	return ((char *) _memcpy(new, s, len));
}
