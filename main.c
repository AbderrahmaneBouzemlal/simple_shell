#include "main.h"
/**
 * main - entry point
 * @av: argument vector
 * @ac: argument count
 * @env: environment
 * return: 0 when succeed and 1 when it fails
 */
int main(int ac, char **av, char **env)
{
	char **str;
	char *line = NULL;
	size_t n = 0;
	ssize_t read;
	(void)ac;
	(void)av;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &n, stdin);
		
		if (read == -1)
		{
			putchar('\n');
			free(line);
			return (1);
		}
		str = split(line);

		if (str == NULL)
		{
			while (*str)
				free(*str);
			exit(1);
		}

		execute(str, env);
		free (str);
	}
	while (*str)
		free(*str);
	free (line);
	return (0);
}
