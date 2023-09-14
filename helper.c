#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: 0 on success, else -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _getline - reads entire line from stream
 *
 * Return: number of characters, else -1
 */
char *_getline(void)
{
	char *line = NULL;
	size_t buff_size = 0;
	ssize_t char_read;

	char_read = getline(&line, &buff_size, stdin);
	if (char_read == -1)
	{
		perror("getline");
	}

	return (line);
}

/**
 * _strtok - extract tokens from string
 * @line: argument input
 * Return: a pointer to the next token, else NULL
 */
char **_strtok(char *line)
{
	char *str_dup = _strdup(line);
	char **str = malloc(sizeof(char *) * (strlen(str_dup) + 1));
	static char *delim = " ";
	char *token;
	int i = 0;

	token = strtok(str_dup, delim);

	while (token != NULL)
	{
		str[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	str[i] = NULL;

	free(str_dup);
	return (str);
}

/**
 * _strdup - duplicates a string
 * @str: - string to duplicate
 * Return: pointer to the duplicated string, else NULL
 */

char *_strdup(char *str)
{
	char *strdup;
	int len = 0, i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		len++;

	strdup = malloc(sizeof(char) * len + 1);
	if (strdup == NULL)
		return (NULL);

	for (i = 0; i < len ; i++)
		strdup[i] = str[i];

	strdup[len] = '\0';

	if (strdup != NULL)
		free(strdup);

	return (strdup);
}
