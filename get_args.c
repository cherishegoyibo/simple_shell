#include "shell.h"
/**
 * get_args - gets the arguments.
 * @buffer: line entered by the user.
 * @buffer_copy: copied buffer.
 *
 * Return: Nothing.
 */
void get_args(char *buffer, char *buffer_copy)
{
	char *delimiter = " \t\n";
	char *token, **args;
	int tokens_number = 0, i = 0;

	if (!buffer || !buffer_copy)
		exit(0);
	token = strtok(buffer, delimiter);
	for (tokens_number = 0; token; tokens_number++)
		token = strtok(NULL, delimiter);
	printf("Tokens Number: %d\n", tokens_number);
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
	handle_args(args);
	for (i = 0 ; args[i] ; i++)
		free(args[i]);
	free(args);
}
