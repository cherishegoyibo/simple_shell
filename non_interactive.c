#include "shell.h"

/**
 * noninteractive - run shell in noninteractive mode.
 * @program_name: name of the program.
 *
 * Return: Nothing.
 */
void noninteractive(char *program_name)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t n_char;

	if (!program_name)
		exit(0);

	n_char = getline(&buffer, &buffer_size, stdin);
	while (n_char >= 0)
	{
		runShell(buffer, n_char, program_name);
		n_char = getline(&buffer, &buffer_size, stdin);
	}

	free(buffer);
}
