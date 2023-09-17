#include "shell.h"

/**
 * _strcmp - compares two strings.
 * @s1: first parameter.
 * @s2: second parameter.
 *
 * Return: 0 if equal,
 *	-1 if less than,
 *	1 if greater than.
*/

int _strcmp(const char *s1, const char *s2)
{
	int result = 0;

	if (!s1 || !s2)
		exit(1);
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	result = *(const unsigned char *)s1 - *(const unsigned char *)s2;
	if (result != 0)
		result = (result > 0) ? 1 : -1;
	return (result);
}
