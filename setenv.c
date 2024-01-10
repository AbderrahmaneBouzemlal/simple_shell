#include "main.h"
int my_setenv(char *variable, char *value)
{
	int retu = setenv(variable, value, 1);

	if (retu == -1)
		perror("setenv");
	return (retu);
}
int my_unsetenv(char *variable)
{
	int retu = unsetenv(variable);

	if (retu == -1)
		perror("unsetenv");
	return (retu);
}
