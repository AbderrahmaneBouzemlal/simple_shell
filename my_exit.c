#include "main.h"
/**
 * my_exit - function that handle the exit command line
 * @arg: The argument of the command
 * Return: The exit status
 */
int my_exit(char *arg)
{
	long stts = 0;
	char *endptr;

	if (!arg)
		exit(0);
	stts = strtol(arg, &endptr, 10);
	if (*endptr == '\0')
	{
		if (stts < 0)
			return (2);
		exit((int)stts);
	}
	return (2);
} 