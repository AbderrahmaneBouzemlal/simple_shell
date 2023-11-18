#include "main.h"

/**
 * execute - function that execute the commands
 * @argv: A pointer to an array of strings
 * @env: The environment
 * Return: 0 when it succeed and 1 otherwise
 */
int execute(char **argv, char **env)
{
	pid_t chpro;
	int status;
	char *command;

	if (argv == NULL || argv[0] == NULL)
		return (1);
	if (strcmp(argv[0], "exit") == 0)
		exit(0);
	if (access(argv[0], F_OK) == 0)
		command = argv[0];
	else
	{
		command = find(argv[0]);
		if (command == NULL)
		{
			perror("./shell");
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
			perror("./shell");
			return (1);
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
