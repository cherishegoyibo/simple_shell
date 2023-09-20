#include "shell.h"

/**
 * __exit - exit the program and free memory.
 * @args: arguments list.
 * @buffer: buffer.
 * @buffer_copy: copy of te buffer.
 *
 * Return: Nothing.
*/
void __exit(char **args, char *buffer, char *buffer_copy)
{
	int i;

	if (!args || !buffer || !buffer_copy)
		exit(2);
	for (i = 0 ; args[i] ; i++)
		free(args[i]);
	free(args);
	free(buffer);
	free(buffer_copy);
	exit(0);
}
/**
 * get_args - gets the arguments.
 * @buffer: line entered by the user.
 * @buffer_copy: copied buffer.
 * @program_name: name of the program.
 *
 * Return: Nothing.
 */
void get_args(char *buffer, char *buffer_copy, char *program_name)
{
	char *delimiter = " \t\n";
	char *token, **args;
	int tokens_number = 0, i = 0;

	if (!buffer || !buffer_copy)
		exit(0);
	token = strtok(buffer, delimiter);
	for (tokens_number = 0; token; tokens_number++)
		token = strtok(NULL, delimiter);
	args = malloc(sizeof(char *) * (tokens_number + 1));
	if  (!args)
	{
		perror("args: malloc error");
		exit(1);
	}
	token = strtok(buffer_copy, delimiter);
	while (token)
	{
		args[i] = malloc(sizeof(char) * (strlen(token) + 1));
		_strcpy(args[i], token);
		token = strtok(NULL, delimiter);
		i++;
	}
	args[i] = NULL;
	if (_strcmp(args[0], "exit") == 0)
		__exit(args, buffer, buffer_copy);
	handle_args(args, program_name);
	for (i = 0 ; args[i] ; i++)
		free(args[i]);
	free(args);
}
