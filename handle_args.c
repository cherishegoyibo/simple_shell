#include "shell.h"

/**
 * execute_command - executes the command by forking new process.
 * @command: command to be executed.
 * @args: arguments.
 * Return: Nothing.
 */

void execute_command(char *command, char **args)
{
	int status;
	pid_t pid;

	if (command && args)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(command, args, environ) == -1)
			{
				perror("Error: executing the command.");
				exit(1);
			}
		}
		else
			wait(&status);
	}
}

/**
 * handle_args - Handles the args.
 * @args: contains the arguments.
 * @program_name: name of the program.
 * Return: Nothing.
 */

void handle_args(char **args, char *program_name)
{
	char *command = NULL, *full_command = NULL, *msg = NULL, *test_msg;
	struct stat st;

	if (args)
	{
		command = args[0];
		if (_strcmp(command, "env") == 0)
			_env();
		else
		{
			full_command = get_full_command_location(command);
			if (full_command)
			{
				execute_command(full_command, args);
				free(full_command);
			}
			else if (stat(command, &st) == 0)
                        	execute_command(command, args);
			else
			{
				test_msg = ": : command not found";
				msg = malloc(sizeof(char) *
(_strlen(test_msg) + _strlen(command) + _strlen(program_name) + 1));
				_strcpy(msg, program_name);
				_strcat(msg, ": ");
				_strcat(msg, command);
				_strcat(msg, ": command not found\0");
				_puts(msg);
				free(msg);
			}
		}
	}
}
