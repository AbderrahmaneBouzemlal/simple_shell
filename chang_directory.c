#include "main.h"
/**
 * change_directory - A built-in function to change the directory
 * @path: the path where to change
 * Return: integer
 */
int change_directory(char *path)
{
	char curr_path[BUFFER_SIZE];

	if (path == NULL)
	{
		path = _getenv("HOME");
		if (path == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (1);
		}
	}
	else if (strcmp(path, "-") == 0)
	{
		path = _getenv("OLDPWD");
		if (path == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (1);
		}
	}
	if (getcwd(curr_path, sizeof(curr_path)) == NULL)
	{
		perror("cd");
		return (1);
	}
	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	my_setenv("PWD", getcwd(curr_path, sizeof(curr_path)));
	return (0);
}
