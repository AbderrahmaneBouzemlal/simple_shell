#include "main.h"

/**
 * execute - function that execute the commands
 * @argv: A pointer to an array of strings
 * @env: The environment
 * @av: vector of arguments passed by to the shell
 * Return: 0 when it succeed and 1 otherwise
 */
int execute(char **argv, char **env, char **av)
{
	pid_t chpro;
	int status;
	char *command;

	if (argv == NULL || argv[0] == NULL)
		return (0);
	if (_strcmp(argv[0], "exit") == 0)
		exit(0);
	if (access(argv[0], F_OK) == 0)
		command = argv[0];
	else
	{
		command = find(argv[0]);
		if (command == NULL)
		{
			return (1);
		}
	}
	chpro = fork();
	if (chpro == -1)
		exit(1);
	if (chpro == 0)
	{
		if (execve(command, argv, env) == -1)
		{
			perror(av[0]);
			return (2);
		}
	}
	else
	{
		waitpid(chpro, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	free(command);
	return (0);
}
