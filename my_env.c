#include "main.h"
/**
 * my_env - print the environment
 * @env: the environment variabales
 * Return: void
 */
void my_env(char **env)
{
	int i = 0;

	for (; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
