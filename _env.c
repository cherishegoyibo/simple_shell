#include "shell.h"

/**
 * _env - prints environment variables.
 *
 * Return: Nothing.
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}
