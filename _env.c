#include "shell.h"

/**
 * print_rev -  prints a string, in reverse.
 * @s: string to be printed.
 *
 * Return: Nothing
*/

void print_rev(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	while (i--)
		_putchar(s[i]);
	_putchar('\n');
}

/**
 * _env - prints environment variables.
 *
 * Return: Nothing.
 */
void _env(void)
{
	int i = 0;
	/*int env_count = 0;*/

	while (environ[i])
        {
                
                _puts(environ[i]);
                i++;
        }
	/*while (environ[i])
	{
		
		env_count++;
		i++;
	}
	while (environ[env_count - 1])
        {

                _puts(environ[env_count]);
                env_count--;
        }*/
}
