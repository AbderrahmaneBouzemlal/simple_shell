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
	int i = 0;
	(void)ac;
	(void)av;

	i = loop(env);
	return (i);
}
