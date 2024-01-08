#include "main.h"
/**
 * err_handle - In this function we will try to handle the errors
 * @error_number: the number that determine which error it is
 * @count: The count of the processes
 * @shell_name: The name of our progrem (shell)
 * @command: the command
 * @errorText: The message
 * @Argument: is the argument passed to the shell
 * Return: The exit status
 */
int err_handle(int error_number, char *shell_name,
		int count, char *command, char *Argument, char *errorText)
{
	int r;

	if (error_number != 5)
		r = fprintf(stderr, "%s: %d: %s: %s", shell_name, count, command, errorText);
	else
	{
		strcat(Argument, "\n");
		r = fprintf(stderr, "%s: %d: %s: %s: %s",
				shell_name, count, command, "Illegal number", Argument);
	}
	return (r);
}
