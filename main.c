#include "main.h"
/**
 * main - entry point
 * @av: argument vector
 * @ac: argument count
 * @env: environment
 * Return: 0 when succeed and 1 when it fails
 */
int main(int ac, char **av, char **env)
{
	int i;
	char **str;
	char *line = NULL;
	size_t n = 0;
	ssize_t read;
	(void)ac;
	(void)av;

	while (1)
	{
		write(1, "$ ", 2);
		read = getline(&line, &n, stdin);

		if (read == -1)
		{
			write(1, "\n", 1);
			free(line);
			return (1);
		}
		str = split(line);

		if (str == NULL)
		{
			for (i = 0; str[i] != NULL; i++)
				free(str[i]);
			free(str);
			exit(1);
		}

		execute(str, env);
		free(str);
	}
	free(line);
	return (0);
}