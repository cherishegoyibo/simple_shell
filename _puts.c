#include "shell.h"

/**
 * _puts - prints a string, followed by a new line, to stdout.
 * @str: string parameter
 *
 * Return: Nothing
*/

void _puts(char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			_putchar(*str);
			str++;
		}
		_putchar('\n');
	}
}
