#include "main.h"
/**
 * is_delim - checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiter
 * Return: 1 if true, 0 if false
 */
unsigned int is_delim(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
/**
 * _strtok - tokenizes a string
 * @srcString: string to tokenize
 * @delim: delimiter
 * Return: pointer to the next token
 */
char *_strtok(char *srcString, const char *delim)
{
	static char *backup_string;
	char *ret = srcString;

	if (!srcString)
	{
		srcString = backup_string;
	}
	if (!srcString)
	{
		return (NULL);
	}
	while (is_delim(*srcString, delim))
	{
		srcString++;
	}
	if (*srcString == '\0')
	{
		backup_string = srcString;
		return (NULL);
	}
	ret = srcString;
	while (*srcString != '\0' && !is_delim(*srcString, delim))
	{
		srcString++;
	}
	if (*srcString == '\0')
	{
		backup_string = srcString;
	}
	else
	{
		*srcString = '\0';
		backup_string = srcString + 1;
	}
	return (ret);
}
