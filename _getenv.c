#include "shell.h"

/**
 * _getenv - gets the environment variables
 * @name: environment variable name.
 *
 * Return: environment variables value.
 */

char *_getenv(const char *name)
{
	char *environ_variable = NULL, *environ_name, *environ_value, *env;
	int i = 0;

	if (!name)
		return (NULL);
	while (environ[i])
	{
		environ_variable = malloc(sizeof(char) * (_strlen(environ[i]) + 1));
		if (!environ_variable)
		{
			perror("malloc");
			exit(1);
		}
		_strcpy(environ_variable, environ[i]);
		environ_name = strtok(environ_variable, "=");
		if (_strcmp(environ_name, name) == 0)
		{
			environ_value = strtok(NULL, "\n");
			env = malloc(sizeof(char) * (_strlen(environ_value) + 1));
			_strcpy(env, environ_value);
			free(environ_variable);
			return (env);
		}
		free(environ_variable);
		i++;
	}
	return (NULL);
}
