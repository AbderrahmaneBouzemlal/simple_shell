#include "main.h"
/**
 * my_getline - function to get input from the user
 * @lineptr: the address of the buffer containing the text
 * @n: The size of the lineptr
 * @stream: the stream that the line is in
 * Return: The number of the characters ridden (success)
 * Otherwise in faillure return -1 and in EOF case also
 */
ssize_t my_getline(char **restrict pline, size_t *restrict len,FILE *restrict fp)
{
	if (pline == NULL || len == NULL) 
	{
		fputs("Error! Bad arguments.\n", stderr);
		return (-1);
	}

	if (fp == NULL) 
	{
		fputs("Error! Bad file pointer.\n", stderr);
		return (-1);
	}
	char chunk [BUFFER_SIZE];
	if (*pline == NULL)
	{
		*len = sizeof(chunk);
		if ((*pline = malloc(*len)) == NULL)
		{
			perror("Unable to allocate memory for the line buffer.");
			return (-1);
		}
		(*pline) [0] = '\0';
		return (-1);
}
