#include "shell.h"

/**
 * **split_string - function that split a given string into an array of tokens
 * @buffer: the input string to be split
 * @deli: the delimiter used to separate the string into tokens.
 *
 * Return: tokens
 */

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
