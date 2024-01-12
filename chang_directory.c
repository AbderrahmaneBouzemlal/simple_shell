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
		if (!path)
			return (0);
	}
	else if (strcmp(path, "-") == 0)
	{
		path = _getenv("OLDPWD");
		printf("%s\n", path);
		if (!path)
			return (0);
	}
	if (getcwd(curr_path, sizeof(curr_path)) == NULL)
		return (-7);
	if (chdir(path) == -1)
		return (-7);
	my_setenv("PWD", getcwd(curr_path, sizeof(curr_path)));
	return (0);
}
