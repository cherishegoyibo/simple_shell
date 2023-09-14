#include "shell.h"

/**
 * execute_command - executes the command by forking new process.
 * @command: command to be executed.
 * @args: arguments.
 * Return: Nothing. 
 */

void execute_command(char *command, char **args)
{
	pid_t pid;
	
	if (command && args)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(command, args, NULL) == -1)
				perror("Error:");
			else
				wait(NULL);
		}
	}
}

/**
 * handle_args - Handles the args.
 * @args: contains the arguments.
 *
 * Return: Nothing.
 */

void handle_args(char **args)
{
	char *command = NULL, *full_command = NULL;
	
	if (args)
	{
		command = args[0];
		full_command = get_full_command_location(command);
		if (full_command)
		{	
			execute_command(full_command, args);
			free(full_command);
		}
		else
		{
			printf("command: %s\n", command);
		}
	}
}
