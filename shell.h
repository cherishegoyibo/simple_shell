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
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

void noninteractive(char *program_name);
void interactive(char *program_name);
void runShell(char *buffer, ssize_t n_char, char *program_name);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
void handle_CTRL_C(int sig);
void get_args(char *buffer, char *buffer_copy, char *program_name);
void handle_args(char **args, char *program_name);
char *get_full_command_location(char *command);
char *_getenv(const char *name);
void _env(void);
int _putchar(char c);
void _puts(char *str);
int _setenv(char *name, char *value);

#endif
