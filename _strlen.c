#include "shell.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: pointer passed.
 *
 * Return: int length of string.
*/

int _strlen(char *s)
{
	int length;

	for (length = 0; *s != '\0'; s++)
		++length;
	return (length);
}
