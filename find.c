#include "main.h"
/**
 * find - function to find the command
 * @command: the command to look for it
 * Return: The full path of the executable file
 */
char *find(char *command)
{
	struct stat st;
	char *path;
	char *path_copy;
	char *token;
	char *cmd_full = NULL;

	if (stat(command, &st) == 0)
		return (command);
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	if (command == NULL || path == NULL)
		return (NULL);
	if (stat(command, &st) == 0)
		return (command);
	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);

	token = _strtok(path_copy, ":");
	cmd_full = find_command(command, token);
	free(path_copy);
	return (cmd_full);
}
/**
 * find_command - search for the command in the token
 * @token: the token
 * @command: the command
 * Return: the full command and NULL when failled
 */
char *find_command(char *command, char *token)
{
	struct stat st;
	char *cmd_full = NULL;

	while (token)
	{
		cmd_full = malloc(my_strlen(token) + my_strlen(command) + 2);
		if (cmd_full == NULL)
			return (NULL);

		my_strcpy(cmd_full, token);
		my_strcat(cmd_full, "/");
		my_strcat(cmd_full, command);

		if (stat(cmd_full, &st) == 0)
			break;
		free(cmd_full);
		cmd_full = NULL;
		token = _strtok(NULL, ":");
	}
	return (cmd_full);
}
