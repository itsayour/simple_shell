#include "shell.h"

/**
 * _getenv - function that searches for and retrieves
 *	the value of the envirement
 *
 * @env_var: the variable to retrieve the value of
 *
 * Return: env_var value, if not return NULL
 */

char *_getenv(const char *env_var)
{
	int i = 0;
	char *key;

	while (environ[i])
	{
		key = strtok(environ[i], "=");
		if (_strcmp(key, env_var) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
