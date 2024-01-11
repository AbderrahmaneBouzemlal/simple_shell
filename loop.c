#include "main.h"
#include "string.h"
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
		for (i = 0; str[i] != NULL; i++)
			free(str[i]);
		free(str);
		}
	free(line);
	return (retu_exec);
}
