#include "shell.h"

/**
 * builtins_func - passes the command and check if builtin.
 * @command: command argument.
 *
 * Return: function pointer of the builtin command
 */
/*int (*builtins_func(char *commandi))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },i
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}*/
