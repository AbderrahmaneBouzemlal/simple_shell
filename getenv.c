#include "main.h"
/**
 * _getenv - function that get a variable from the environment
 * @var: The variable we are going to look for
 * Return: A pointer to a string
 */
char *_getenv(const char *var)
{
	register const char *np;
	register int len;
	register char **p, *c;

	if (var == NULL || environ == NULL)
		return (NULL);

	for (np = var; *np && *np != '='; ++np)
	{
		continue;
	}
	len = np - var;
	for (p = environ; (c = *p) != NULL; ++p)
		if (strncmp(c, var, len) == 0 && c[len] == '=')
		{
			return (c + len + 1);
		}
	return (NULL);
}
