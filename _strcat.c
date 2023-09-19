#include "shell.h"

/**
 * _strcat -  concatenates two strings.
 * @dest: destination
 * @src: source
 * Return: concatination of dest and src,
 *	NULL on failure.
 */

char *_strcat(char *dest, const char *src)
{
	char *destPtr;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	destPtr = dest + _strlen(dest);
	while (*src != '\0')
		*destPtr++ = *src++;
	*destPtr = '\0';
	return (destPtr);
}
