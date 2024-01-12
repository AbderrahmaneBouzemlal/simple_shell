#include "main.h"
/**
 * my_exit - function that handle the exit command line
 * @arg: The argument of the command
 * Return: The exit status
 */
int my_exit(char *arg, char **tokens, char *line_buffer)
{
	long stts = 0;
	char *endptr;

	if (!arg)
	{
		cleanup(tokens, line_buffer);
		exit(0);
	}

	stts = strtol(arg, &endptr, 10);
	if (*endptr != '\0' || stts < 0)
		return (2);
	cleanup(tokens, line_buffer);
	exit((int)stts);
}
void cleanup(char **tokens, char *line_buffer)
{
	int i;

	if (line_buffer)
		free(line_buffer);
	if (tokens)
	{
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		free(tokens);
	}
}
