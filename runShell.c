#include "shell.h"

/**
 * runShell - runs the shell.
 * @buffer: line entered by the user.
 * @n_char: number of characters.
 * _strcpy(buffer_copy, buffer);
        handle_args(buffer, buffer_copy);
 * Return: Nothing.
 */
void runShell(char *buffer, ssize_t n_char)
{
	char *buffer_copy = NULL;

	buffer_copy = malloc(sizeof(char) * (n_char + 1));
	if (buffer_copy == NULL)
	{
		perror("buffer_copy: malloc error");
		exit(1);
	}
	_strcpy(buffer_copy, buffer);
	get_args(buffer, buffer_copy);
	free(buffer_copy);
}