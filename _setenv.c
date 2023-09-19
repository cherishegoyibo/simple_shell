#include "shell.h"

/**
 * var_data - create env data.
 * @name: env name.
 * @value: env value.
 *
 * Return: env data.
 */

char *var_data(char *name, char *value)
{
	char *env_data;
	int name_length, value_length, length;

	if (!name || !value)
		return (NULL);
	name_length = _strlen(name);
	value_length = _strlen(value);
	length = name_length + value_length + 2;
	env_data = malloc(sizeof(char) * (length));
	_strcpy(env_data, name);
	_strcat(env_data, "=");
	_strcat(env_data, value);
	_strcat(env_data, "\0");

	return (env_data);
}

/**
 * _setenv - set environment variable.
 * @name: variable name.
 * @value: value.
 *
 * Return: 0 on success,
 *	-1 on failure.
 */
int _setenv(char *name, char *value)
{
	int i = 0;/*, len = 0;*/
	char *var, *var_copy = NULL, *var_name, *new_var;

	if (!name || !value)
		return (-1);
	var = _getenv(name);
	if (var)
	{
		for ( i = 0; environ[i]; i++)
		{
			var_copy = malloc(sizeof(char) * (_strlen(environ[i]) + 1));
			if (!var_copy)
			{
				perror("malloc");
				exit(1);
			}
			var_copy = _strcpy(var_copy, environ[i]);
			var_name = strtok(var_copy, "=");
			if (_strcmp(var_name, name) == 0)
			{
				free(var);
				environ[i] = var_data(name, value);
				free(var_copy);
				return 0;
			}
			free(var_copy);
		}
	}
	else
	{
		i = 0;
		while (environ[i])
			i++;

		new_var = var_data(name, value);
		 _strcpy(environ[i], new_var);
		environ[i + 1] = NULL;
		free(new_var);
	}
	free(var);
	return (0);
}
