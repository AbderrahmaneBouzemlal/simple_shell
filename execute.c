#include "main.h"
/**
 * execute_command - function that handle the execution part
 * @command: The command to be executed
 * @argv: A pointer to an array of strings
 * @env: The environment
 * @av: vector of arguments passed by to the shell
 * Return: void
 */
void execute_command(char *command, char **argv, char **env, char **av)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command, argv, env) == -1)
		{
			perror(av[0]);
			_exit(EXIT_FAILURE);
		}
		_exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror(av[0]);
		free(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (command != argv[0])
			free(command);
	}
}
/**
 * execute - function that execute the commands
 * @argv: A pointer to an array of strings
 * @env: The environment
 * @av: vector of arguments passed by to the shell
 * Return: 0 when it succeed and 1 otherwise
 */
int execute(char **argv, char **env, char **av)
{
	char *command;

	if (argv == NULL || argv[0] == NULL)
		return (0);
	if (strcmp(argv[0], "env") == 0)
	{
		my_env(env);
		return (0);
	}
	else if (strcmp(argv[0], "exit") == 0)
		return (-5);
	else if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL)
			return (my_setenv(argv[0], argv[1]));
		perror("few arguments");
		return (1);
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
		return (my_unsetenv(argv[0]));
	else if (strcmp(argv[0], "cd") == 0)
		return (change_directory(argv[1]));

	command = find(argv[0]);
	if (command == NULL)
		return (127);

	execute_command(command, argv, env, av);

	return (0);
}
