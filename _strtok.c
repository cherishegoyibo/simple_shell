#include "shell.h"

/**
 * is_delim - checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiter character
 * Return: 1 on success, else 0
 */
int is_delim(char c, const char *delim)
{
	size_t i = 0;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strtok - a function that tokinize string into tokens using delimiter
 * @str: string
 * @delim: Delimiter
 *
 * Return: pointer to the next token, else NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *p;
	char *strt = NULL;

	if (str)
	{
		p = str;
	}
	else if (p == NULL)
	{
		return (NULL);
	}

	while (*p != '\0' && is_delim(*p, delim))
	{
		p++;
	}
	if (*p == '\0')
	{
		p = NULL;
		return (NULL);
	}

	strt = p;
	while (*p != '\0' && !is_delim(*p, delim))
	{
		p++;
	}
	if (*p != '\0')
	{
		*p = '\0';
		p++;
	}

	return (strt);
}
