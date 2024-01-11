#include "main.h"
/**
 * split - splits the line into arguments
 * @line: The line to be spliten
 * Return: a pointer to an array of strings
 */
char **split(char *line)
{
	int i = 0;
	char *token;
	char **tmp;
	char **str;
	int chunk = BUFFER_SIZE;

	if (line == NULL || *line == '\0')
		return (NULL);

	str = malloc(sizeof(char *) * BUFFER_SIZE);
	if (str == NULL)
		return (NULL);
	token = _strtok(line, " \n\t");
	while (token)
	{
		if (i >= chunk - 1)
		{
			tmp = realloc(str, (chunk * 2) * sizeof(char *));
			if (tmp == NULL)
			{
				free_tokens(str, i);
				return (NULL);
			}
			str = tmp;
			chunk *= 2;
		}
		str[i] = _strdup(token);
		if (str[i] == NULL)
		{
			free_tokens(str, i);
			return (NULL);
		}
		i++;
		token = _strtok(NULL, " \n\t");
	}
	str[i] = NULL;
	return (str);
}
/**
 * free_tokens - function that free the tokens
 * @tokens: The tokens that to be freed
 * @count: the count of the blocks
 * return: nothing
 */
void free_tokens(char **tokens, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(tokens[i]);
	free(tokens);
}
