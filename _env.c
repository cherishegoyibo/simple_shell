#include "shell.h"

/**
 * _env - prints environment variables.
 * @sh_data: shell data struct.
 *
 * Return: Nothing.
 */
void _env(shell_data *sh_data)
{
	int i = 0;

	while (sh_data->_environ[i])
	{
		_puts(sh_data->_environ[i]);
		i++;
	}
}
