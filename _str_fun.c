#include <stdio.h>

/**
 * _strlen - return the length of parsing param
 * @s: string passing pointer
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	if (s[0] == '\0')
	{
		return (0);
	}
	return (1 + _strlen(&s[1]));

}
