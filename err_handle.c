#include "main.h"
/***
 * err_hand - function that handle the error
 * @retu_exec: The return of the execve
 * @shell: The name of the shell
 * @count: The number of the command line
 * @command: The command
 * @argument: The argument
 * Return: The return of the execve
 */
int err_hand(int retu_exec, char *shell, int count,
		char *command, char *argument, char *line, char **str)
{
	if (retu_exec == 127)
		fprintf(stderr, "%s: %d: %s: not found\n"
				, shell, count, command);
	else if (retu_exec == -5)
	{
		retu_exec = my_exit(str[1], str, line);
		if (retu_exec == 2)
			fprintf(stderr, "%s: %d: %s: Illegal number: %s\n"
					, shell, count, command, argument);
	}
	else if (retu_exec == -7)
		fprintf(stderr, "%s: %d: %s: can't cd to %s\n"
				, shell, count, command, argument);
	return (retu_exec);
}
