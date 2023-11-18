#include "main.h"
/**
 * find - function to find the command
 * @command: the command to look for it
 * Return: The full path of the executable file
 */
char *find(char *command)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *token = _strtok(path_copy, ":");
	char *cmd_full = NULL;
	struct stat st;

	if (command == NULL)
		return (NULL);
	while (token)
	{
		cmd_full = malloc(_strlen(token) + _strlen(command) + 2);

		if (cmd_full == NULL)
		{
			free(path_copy);
			exit(0);
		}

		_strcpy(cmd_full, token);
		_strcat(cmd_full, "/");
		_strcat(cmd_full, command);

		if (stat(cmd_full, &st) == 0)
		{
			free(path_copy);
			return (cmd_full);
		}

		free(cmd_full);
		token = _strtok(NULL, ":");
	}
	free(path_copy);

	return (NULL);
}
