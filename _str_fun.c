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

	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
