#include "shell.h"

int main()
{
	char *buffer = NULL;
	size_t buffer_size =  0;
	char **args = NULL;
	char *token;
	int status, i = 0;
	int n_char;
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		n_char = getline(&buffer, &buffer_size, stdin);
		if (n_char == -1)
		{
			perror("failure");
			exit(EXIT_FAILURE);
		}
		token = strtok(buffer, " \n\t");
		while (token)
		{
		i++;
		args = realloc(args, sizeof(char *) * i);
	        args[i - 1] = token;
		token = strtok(NULL, " \n\t");
		}
	       pid = fork();

		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
			}
		}
		else
			wait(&status);
	i = 0;
	free(args);
	}
	exit(EXIT_SUCCESS);
}
