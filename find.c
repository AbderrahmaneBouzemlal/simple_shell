#include "main.h"
/**
 * find - function to find the command
 * @command: the command to look for it
 * Return: The full path of the executable file
 */
char *find(char *command)
{
	char *path = _getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *cmd_full = NULL;
	struct stat st;

	if (command == NULL)
		return (NULL);
	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(command) + 2);

		if (cmd_full == NULL)
		{
			free(path_copy);
			exit(0);
		}

		strcpy(cmd_full, token);
		strcat(cmd_full, "/");
		strcat(cmd_full, command);

		if (stat(cmd_full, &st) == 0)
		{
			free(path_copy);
			return (cmd_full);
		}

		free(cmd_full);
		token = strtok(NULL, ":");
	}
	free(path_copy);

	return (NULL);
}
