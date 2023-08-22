#include "shell.h"

char **split_string(char *buffer, char *deli)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	token = strtok(buffer, deli);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, deli);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
