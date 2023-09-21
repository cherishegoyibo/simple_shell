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
	if (!env_data)
	{
		perror("malloc error");
		exit(1);
	}
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
 * @sh_data: shell data struct.
 *
 * Return: 0 on success,
 *	-1 on failure.
 */
int _setenv(char *name, char *value, shell_data *sh_data)
{
	int i = 0;
	char *var_copy = NULL, *var_name, *new_var;

	if (!name || !value)
		return (-1);
	for (i = 0; sh_data->_environ[i]; i++)
	{
		var_copy = malloc(sizeof(char) * (_strlen(sh_data->_environ[i]) + 1));
		if (!var_copy)
		{
			perror("malloc");
			exit(1);
		}
		var_copy = _strcpy(var_copy, sh_data->_environ[i]);
		var_name = _strtok(var_copy, "=");
		if (_strcmp(var_name, name) == 0)
		{
			new_var = var_data(name, value);
			_strcpy(sh_data->_environ[i], new_var);
			free(var_copy);
			free(new_var);
			return (0);
		}
		free(var_copy);
	}
	new_var = var_data(name, value);
	sh_data->_environ[i] = malloc(sizeof(char) * (_strlen(new_var) + 1));
	if (!sh_data->_environ[i])
	{
		perror("realloc error");
		exit(1);
	}
	_strcpy(sh_data->_environ[i], new_var);
	sh_data->_environ[i + 1] = malloc(sizeof(char));
	sh_data->_environ[i + 1] = NULL;
	free(new_var);
	return (0);
}
