#include "main.h"
/**
 * execute - function that execute the commands
 * @argv: A pointer to an array of strings
 * @env: The environment
 * @av: vector of arguments passed by to the shell
 * Return: 0 when it succeed and 1 otherwise
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
			free(command);
			exit(EXIT_FAILURE);
		}

	}
	else if (child_pid < 0)
	{
		perror(av[0]);
		free(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		do
		{
			waitpid(child_pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (command != argv[0])
		{
			free(command);
		}
	}
}

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

	if (strcmp(argv[0], "exit") == 0)
		return my_exit(argv[1]);

	command = find(argv[0]);

	if (command == NULL)
		return (127);

	execute_command(command, argv, env, av);

	return (1);
}
