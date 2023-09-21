#include "shell.h"

/**
 * is_delimiter - It checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiter character
 * Return: 1 on success, else 0
 */
int is_delimiter(char c, const char *delim)
{
	size_t i = 0;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}
/**
 * _strtok - It tokinizes the string into tokens using delimiter.
 * @str: string to be tokinized.
 * @delim: Delimiter used in tokenization.
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

	while (*p != '\0' && is_delimiter(*p, delim))
	{
		p++;
	}
	if (*p == '\0')
	{
		p = NULL;
		return (NULL);
	}

	strt = p;
	while (*p != '\0' && !is_delimiter(*p, delim))
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
