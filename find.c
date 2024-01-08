#include "main.h"
/**
 * find - function to find the command
 * @command: the command to look for it
 * Return: The full path of the executable file
 */
char *find(char *command)
{
	char *path;
	char *path_copy;
	char *token;
	char *cmd_full = NULL;

	if (command == NULL)
		return (NULL);
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	token = _strtok(path_copy, ":");
	cmd_full = find_command(command, token);
	return (cmd_full);
}
/**
 * find_command - search for the command in the token
 * @token: the token
 * return: the full command and NULL when failled
 */
char *find_command(char *command, char *token)
{
	struct stat st;
	char *cmd_full = NULL;

	while (token)
	{
		cmd_full = malloc(_strlen(token) + _strlen(command) + 2);
		if (cmd_full == NULL)
			return (NULL);

		strcpy(cmd_full, token);
		strcat(cmd_full, "/");
		strcat(cmd_full, command);

		if (stat(cmd_full, &st) == 0)
			break;
		cmd_full = NULL;
		token = _strtok(NULL, ":");
	}
	return (cmd_full);
}
