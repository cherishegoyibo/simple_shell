#include "shell.h"
/**
 * set_shell_data - Initializes shell data struct.
 * @sh_data: data structure
 *
 * Return: Nothing.
 */
void set_shell_data(shell_data *sh_data)
{
	unsigned int i;

	sh_data->status = 0;
	for (i = 0; environ[i]; i++)
		;

	sh_data->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		sh_data->_environ[i] = malloc(sizeof(char) * (_strlen(environ[i]) + 1));
		_strcpy(sh_data->_environ[i], environ[i]);
	}

	sh_data->_environ[i] = NULL;
}

/**
 * free_shell_data - frees shell data struct.
 * @sh_data: shell data struct
 *
 * Return: Nothing.
 */
void free_shell_data(shell_data *sh_data)
{
	unsigned int i;

	for (i = 0; sh_data->_environ[i]; i++)
	{
		free(sh_data->_environ[i]);
	}
	free(sh_data->_environ);
}

/**
 * main - It is the main function.
 * @ac: number of items in av.
 * @av: NULL terminated array of strings.
 *
 * Return: Nothing
*/
int main(int ac, char **av)
{
	shell_data sh_data;

	if (ac != 1)
		return (0);
	set_shell_data(&sh_data);
	if (isatty(STDIN_FILENO))
	{
		signal(SIGINT, handle_CTRL_C);
		interactive(&sh_data, av[0]);
	}
	else
	{
		noninteractive(&sh_data, av[0]);
	}
	free_shell_data(&sh_data);
	return (0);
}
