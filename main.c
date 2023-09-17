#include "shell.h"

/**
 * main - It is the main function.
 * @ac: number of items in av.
 * @av: NULL terminated array of strings.
 *
 * Return: Nothing
*/
int main(int ac, char **av)
{
	if (ac != 1)
		return (0);
	if (isatty(STDIN_FILENO))
	{
		signal(SIGINT, handle_CTRL_C);
		interactive();
	}
	else
	{
		noninteractive(av[0]);
	}

	return (0);
}
