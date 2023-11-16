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

	if (argv == NULL)
		return (1);

	if (strcmp(argv[0], "exit") == 0)
		exit(0);

	command = find(argv[0]);

	if (command == NULL)
	{
		perror("./shell");
		return (1);
	}
	chpro = fork();
	if (chpro == -1)
		exit(1);
	if (chpro == 0)
	{
		if (execve(command, argv, env) == -1)
		{
			perror("./shell");
			exit(0);
		}
	}
	else
		waitpid(chpro, &status, 0);
	free(command);
	return (0);
}
