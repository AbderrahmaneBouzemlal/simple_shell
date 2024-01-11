#include "main.h"
int my_strlen(char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return length;
}
