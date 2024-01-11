#include "main.h"

char* my_strcpy(char *dest, char *src)
{
	char *originalDest = dest;

	while ((*dest++ = *src++) != '\0');
	return (originalDest);
}

char* my_strcat(char *dest, char *src)
{
	char *originalDest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while ((*dest++ = *src++) != '\0');

	return (originalDest);
}
