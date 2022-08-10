#include <stdio.h>
#include "shell.h"
#include <string.h>
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

/**
 * _strcat - check the code
 * @dest: char tab representing the destination
 * @src: char tab representing the source
 *
 * Return: char tab
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	char *cat;

	cat = malloc(_strlen(dest) + _strlen(src));
	while (dest[i])
	{
		cat[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		cat[i] = src[j];
		i++;
		j++;
	}
	return (cat);
}

/**
 * get_pathenv_var -  Get the pathenv var object
 *
 * Return: char*
 */
char *get_pathenv_var()
{
	unsigned int i, pos;
	char *_path;

	i = 0;
	while (environ[i])
	{
		if (_str_startby("PATH=", environ[i]) == 0)
		{
			_path = malloc((_strlen(environ[i]) - 5) * sizeof(char));
			pos = 5;
			while (environ[i][pos])
			{
				_path[pos - 5] = environ[i][pos];
				pos++;
			}

			return (_path);
		}
		i++;
	}
	return (NULL);
}

/**
 * _strcmp - compare two strings
 * @s1: fisrt string
 * @s2: second string
 *
 * Return: char tab
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _str_startby - check if s2 start by s1
 * @s1: fisrt string
 * @s2: second string
 *
 * Return: char tab
 */
int _str_startby(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s2[i] == '\0')
		{
			return (-1);
		}

		if (s1[i] > s2[i] || s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

