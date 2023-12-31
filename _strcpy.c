#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src,
 *	including the terminating null byte
 *	(\0), to the buffer pointed to by dest.
 * @dest: first parameter
 * @src: second parameter
 *
 * Return: the pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
