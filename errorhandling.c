#include "main.h"
/**
 * err_handle - In this function we will try to handle the errors
 * @count: The count of the processes
 * @shell_name: The name of our progrem (shell)
 * @command: the command
 * @errorText: The message
 * Return: The exit status
 */
int err_handle(char *shell_name, int count, char *command, char *errorText)
{
	int r;

	r = fprintf(stderr, "%s: %d: %s: %s", shell_name, count, command, errorText);
	return (r);
}
