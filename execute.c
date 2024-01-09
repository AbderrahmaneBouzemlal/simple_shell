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
	char *command = NULL;

	if (argv == NULL || argv[0] == NULL)
		return (0);

	if (strcmp(argv[0], "exit") == 0)
		return (my_exit(argv[1]));

	if (access(argv[0], F_OK) == 0)
		command = argv[0];
	else
	{
		command = find(argv[0]);
		if (command == NULL)
			return (127);
	}
	chpro = fork();
	if (chpro == -1)
		exit(1);
	if (chpro == 0)
	{
		if (execve(command, argv, env) == -1)
		{
			perror(av[0]);
			free(command);
			_exit(2);
		}
	}
	else
	{
		waitpid(chpro, &status, 0);
		if (command != argv[0])
			free(command);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}
/**
 * my_exit - function that handle the exit command line
 * @arg: The argument of the command
 * return: The exit status
 */
int my_exit(char *arg)
{
	long stts = 0;
	char *endptr;

	if (!arg)
		exit(0);
	stts = strtol(arg, &endptr, 10);
	if (*endptr == '\0')
	{
		if (stts < 0)
			return (5);
		exit((int)stts);
	}
	return (5);
}
