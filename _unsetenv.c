#include "shell.h"

/**
 * _unsetenv - remove an environment variable.
 * @name: Name of the environment variable to remove.
 * @sh_data: shell data struct.
 *
 * Return: 0 if successful or -1 if unsuccessful.
 */
int _unsetenv(char *name, shell_data *sh_data)
{
	char **temp_env;
	char *var_copy, *var_name;
	int i = 0;

	while (sh_data->_environ[i])
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
			temp_env = environ;
			do {
				temp_env[i] = temp_env[i + 1];
				temp_env++;
			} while (**temp_env);
			free(var_copy);
			return (0);
		}
		free(var_copy);
		i++;
	}
	return (0);
}
