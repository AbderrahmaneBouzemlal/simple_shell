#include "main.h"
/**
 * my_setenv - function to add or change a variable in the environment
 * @variable: the name of the variable
 * @value: the value of the variable
 * Return: integer
 */
int my_setenv(char *variable, char *value)
{
	int retu = setenv(variable, value, 1);

	if (retu == -1)
		perror("setenv");
	return (retu);
}
/**
 * my_unsetenv - function to add or change a variable in the environment
 * @variable: the name of the variable
 * Return: integer
 */
int my_unsetenv(char *variable)
{
	int retu = unsetenv(variable);

	if (retu == -1)
		perror("unsetenv");
	return (retu);
}
