#include "main.h"
/**
 * split - splits the line into arguments
 * @line: The line to be spliten
 * Return: a pointer to an array of strings
 */
char **split(char *line)
{
	char *token;
	char **tmp;
	char **str = malloc(sizeof(char *) * BUFFER_SIZE);
	int i = 0;
	int j;

	token = strtok(line, " \n\t");
	while (token)
	{
		str[i] = token;

		if (str[i] == NULL)
		{
			free(str);
			return (NULL);
		}
		i++;

		tmp = realloc(str, (i + 1) * sizeof(char *));
		if (tmp == NULL)
		{
			for (j = 0; str != NULL; j++)
				free(str[j]);
			free(str);
			return (NULL);
		}
		str = tmp;
		token = strtok(NULL, " \n\t");
	}
	str[i] = NULL;
	return (str);
}