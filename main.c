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
	(void)ac;
	(void)av;
	loop(env);
	return (0);
}
