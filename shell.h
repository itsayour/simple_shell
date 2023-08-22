#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <ctype.h>

extern char **environ;
char **split_string(char *buffer, char *deli);
char *_getenv(const char *env_var);
char *get_command(char *command);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
int _putchar(char c);
void _puts(char *str);

#endif
