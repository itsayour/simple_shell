#include "shell.h"
#include "split_string.h"
#include "strfunctions.h"

char *get_command(char *command)
{
	char *path = _getenv("PATH");
	char *token;
	char *cmd_full;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
		cmd_full = malloc(_strlen(token) + _strlen(command) + 2);
		_strcpy(cmd_full, token);
		_strcat(cmd_full, "/");
		_strcat(cmd_full, command);
		if (stat(cmd_full, &st) == 0)
			return (cmd_full);
		free(cmd_full);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *cmd;
	char **args;
	pid_t pid;
	int status, n_chars;
	(void) ac;
	(void) av;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		n_chars = getline(&buffer, &buffer_size, stdin);
		if (n_chars == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}
		args = split_string(buffer, " \t\n");
		if (_strcmp(args[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == 0)
		{
			cmd = get_command(args[0]);
			if (cmd)
				execve(cmd, args, env);
			else
				_puts("cmd not found\n");
			exit(0);
		}
		else
		{
			wait(&status);
		}
		return (0);
	}
}
