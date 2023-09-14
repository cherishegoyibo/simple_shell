#include "shell.h"

/**
 * get_command - gets the full command by concating
 *	the command with token.
 * @token: The token.
 * @command: The command.
 * @path_copy: copy of the path to free on error.
 * Return: concated command.
*/
char *get_command(char *command, char *token, char *path_copy)
{
	char *full_command = NULL;

	if (!command || !token)
		return (NULL);
	full_command = malloc(_strlen(command) + _strlen(token) + 2);
	if (!full_command)
	{
		perror("malloc");
		free(path_copy);
		exit(EXIT_FAILURE);
	}
	_strcpy(full_command, token);
	_strcat(full_command, "/");
	_strcat(full_command, command);
	_strcat(full_command, "\0");
	return (full_command);
}
/**
 * get_full_command_location - Gets the full command from the path.
 * @command: Command to check in the path.
 *
 * Return: the full command if found,
 *	Null if not found
*/
char *get_full_command_location(char *command)
{
	char *path = NULL, *path_copy, *token, *full_command;
	struct stat st;

	if (!command)
		return (NULL);
	path = _getenv("PATH");
	if (path)
	{
		printf("PATH: %s\n", path);
		path_copy = malloc(sizeof(char) * (_strlen(path) + 1));
		_strcpy(path_copy, path);
		free(path);
		token = strtok(path_copy, ":");
		while (token)
		{
			full_command = get_command(command, token, path_copy);
			if (stat(full_command, &st) == 0)
			{
				free(path_copy);
				return (full_command);
			}
			else
			{
				free(full_command);
				token = strtok(NULL, ":");
			}
		}
		free(path_copy);
	}
	return (NULL);
}
