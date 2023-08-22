#include "shell.h"
/**
 *  _strlen -  calculates the length of a string.
 * @str: pointer to a string.
 * Return: i.
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
/**
 * _strcat - concatenate two strings
 *
 * @dest: destination string
 * @src: source srting
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - function that compares two strings.
 *
 * @s1: pointer of the first string to be compared.
 * @s2: pointer of the second string to be compared.
 * Return: integer.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
  * _strcpy - copys str to another
  * @dest: destination string
  * @src: the str that we gonna copy
  *
  * Return: the pointer to dst
  */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';

	return (dest);
}
/**
 *  _puts - print string to stdout
 * @str: pointer to string.
 * Return: Always 0.
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
