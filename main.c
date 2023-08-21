#include "shell.h"

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *cmd;
	char **args;
	pid_t pid;
	int status, n_chars;

	while (1)
	{
		write(1,"#cisfun$ ",9);
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
