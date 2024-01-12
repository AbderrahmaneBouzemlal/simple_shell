#include "main.h"
#include "string.h"
/**
 * catch_int - function that handle the ctrl + c
 * @sig_num: The signal number
 * Return: Nothing
 */
void catch_int(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, catch_int);
	write(1, "\n$ ", 3);
	fflush(stdout);
}
/**
 * loop - main loop
 * @env: environment
 * @av: The program arguments
 * Return: 0 on success, 1 on failure
 */
int loop(char **env, char **av)
{
	int count = 0, retu_exec, i;
	char **str = NULL;
	char *line = NULL;
	size_t n = 0;
	ssize_t read;

	signal(SIGINT, catch_int);
	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO) == 1)
		{
			write(1, "$ ", 2);
			fflush(stdout);
		}
		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}
		str = split(line);
		if (str == NULL)
		{
			perror("split");
			continue;
		}
		retu_exec = execute(str, env, av);
		if (retu_exec == 127)
			fprintf(stderr, "%s: %d: %s: not found\n"
					, av[0], count, str[0]);
		else if (retu_exec == -5)
		{
			retu_exec = my_exit(str[1], str, line);
			if (retu_exec == 2)
				fprintf(stderr, "%s: %d: %s: Illegal number: %s\n"
						, av[0], count, str[0], str[1]);
		}

		for (i = 0; str[i] != NULL; i++)
			free(str[i]);
		free(str);
		}
	free(line);
	return (retu_exec);
}
