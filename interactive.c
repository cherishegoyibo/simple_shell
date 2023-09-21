#include "shell.h"

/**
 * interactive - run shell in interactive mode.
 * @sh_data: shell data struct.
 * @program_name: name of the program.
 *
 * Return: Nothing
 */
void interactive(shell_data *sh_data, char *program_name)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t n_char;

	while (1)
	{
		write(1, "$ ", 2);
		n_char = getline(&buffer, &buffer_size, stdin);
		if (n_char == -1)
		{
			free(buffer);
			free_shell_data(sh_data);
			exit(0);
		}
		if (_strcmp(buffer, "\n") != 0)
		{
			runShell(buffer, n_char, program_name, sh_data);
		}
	}
	free(buffer);
}
