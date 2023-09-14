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
	if (n_char != -1)
	{
		buffer[_strlen(buffer) - 1] = '\0';
		printf("%s: 1: %s: not found\n", program_name, buffer);
		/*runShell(buffer, n_char);
		free(buffer);
		exit(0);*/
	}
}
