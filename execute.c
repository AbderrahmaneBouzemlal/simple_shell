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

	if (strcmp(argv[0], "env") == 0)
	{
		my_env(env);
		return (0);
	}
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
	if (chpro == 0)
	{
		if (execve(command, argv, env) == -1)
			perror(av[0]);
		free(command);
		exit(EXIT_FAILURE);
	}
	else if (chpro < 0)
        {
		perror(av[0]);
		free(command);
		exit(EXIT_FAILURE);
        }

	else
	{
		do 
		{
			waitpid(chpro, &status, WUNTRACED);
			if (command != argv[0])
				free(command);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
