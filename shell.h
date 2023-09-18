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

void noninteractive(char *program_name);
void interactive(void);
void runShell(char *buffer, ssize_t n_char);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
void handle_CTRL_C(int sig);
void get_args(char *buffer, char *buffer_copy);
void handle_args(char **args);
char *get_full_command_location(char *command);
char *_getenv(const char *name);
void _env(void);
int _putchar(char c);
void _puts(char *str);

#endif
