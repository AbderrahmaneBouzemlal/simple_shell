#include "main.h"
/**
 * loop - main loop
 * @env: environment
 * Return: 0 on success, 1 on failure
 */
int loop(char **env)
{
	int i;
	char **str;
	char *line = NULL;
	size_t n = 0;
	ssize_t read;

	while (1)
	{
		write(1, "$ ", 2);
		read = getline(&line, &n, stdin);

		if (read == -1)
		{
			free(line);
			exit(0);
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
