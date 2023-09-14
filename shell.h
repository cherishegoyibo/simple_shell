#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv, char **env);
int _putchar(char c);
char *_getline(void);
char **_strtok(char *line);
char *_strdup(char *str);

#endif
