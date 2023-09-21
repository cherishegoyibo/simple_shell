#include "shell.h"

/**
 * noninteractive - run shell in noninteractive mode.
 * @sh_data: shell data struct.
 * @program_name: name of the program.
 *
 * Return: Nothing.
 */
void noninteractive(shell_data *sh_data, char *program_name)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t n_char;

	if (!program_name)
		exit(0);
	do {
		n_char = getline(&buffer, &buffer_size, stdin);
		if (n_char > 1)
			runShell(buffer, n_char, program_name, sh_data);
	} while (n_char >= 0);
	free(buffer);
}
