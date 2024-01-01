#include "main.h"
/**
 * find - function to find the command
 * @command: the command to look for it
 * Return: The full path of the executable file
 */
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *find(char *command)
{
	char *path;
	char *path_copy;
	char *token;
	char *cmd_full = NULL;
	struct stat st;

	if (command == NULL)
		return (NULL);

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		free(path);
		return (NULL);
	}
	
	token = _strtok(path_copy, ":");

	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(command) + 2);
		if (cmd_full == NULL)
		{
			free(path);
			free(path_copy);
			return (NULL);
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
		token = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
