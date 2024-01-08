#include "main.h"
/**
 * my_getline - function to get input from the user
 * @pline: the address of the buffer containing the text
 * @len: The size of the lineptr
 * @fp: the stream that the line is in
 * Return: The number of the characters ridden (success)
 * Otherwise in faillure return -1 and in EOF case also
 */
ssize_t my_getline(char **pline, size_t *len, FILE *fp)
{
	size_t i = 0;
	int c;
	char *temp;

	if (pline == NULL || len == NULL || fp == NULL)
	{
		fputs("Error! Bad arguments or file pointer.\n", stderr);
		return (-1);
	}
	if (*pline == NULL || *len == 0)
	{
		*len = BUFFER_SIZE;
		*pline = malloc(*len);

		if (*pline == NULL)
		{
			perror("Unable to allocate memory for the line buffer.");
			return (-1);
		}
	}
	while ((c = fgetc(fp)) != EOF && c != '\n')
	{
		(*pline)[i++] = (char)c;

		if (i == *len - 1)
		{
			*len *= 2;
			temp = realloc(*pline, *len);
			if (temp == NULL)
				return (-1);
			*pline = temp;
		}
	}
	(*pline)[i] = '\0';
	if (c == EOF && i == 0)
		return (-1);
	return (i);
}
