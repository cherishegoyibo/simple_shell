#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct data - contains shell data on runtime
 * @status: the last status of the shell
 * @_environ: environment variables
 */
typedef struct data
{
	int status;
	char **_environ;
} shell_data;

void noninteractive(shell_data *sh_data, char *program_name);
void interactive(shell_data *sh_data, char *program_name);
void runShell(char *buffer, ssize_t n_char, char *program_name, shell_data *sh_data);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
void handle_CTRL_C(int sig);
void get_args(char *buffer, char *buffer_copy, char *program_name, shell_data *sh_data);
void handle_args(char **args, char *program_name, shell_data *sh_data);
char *get_full_command_location(char *command);
char *_getenv(const char *name);
void _env(shell_data *sh_data);
int _putchar(char c);
void _puts(char *str);
int _setenv(char *name, char *value, shell_data *sh_data);
int _unsetenv(char *name, shell_data *sh_data);
void *_realloc(void *ptr, unsigned int size, unsigned int new_size);
void free_shell_data(shell_data *sh_data);
char *_strtok(char *str, const char *delim);

#endif
