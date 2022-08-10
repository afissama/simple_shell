#include "shell.h"
/**
 * __exit - exit the shell
 *
 * @return int
 */
int __exit()
{
	exit(0);
	return(0);
}

/**
 * __env - prints the current environment
 * 
 */
int __env()
{
	size_t pos_i;

	pos_i =0;
	while (environ[pos_i])
	{
		write(1, environ[pos_i], _strlen(environ[pos_i]));
		write(1, "\n", 1);
		pos_i++;
	}
	return (1);
}
/**
 * add_builtin - add new builtin to the end of list
 * 
 * @root: root elem
 * @name: comman name
 * @func: fucntion to execute
 * Return: a builtins* 
 */
builtins *add_builtin(builtins **root, char *name, int(*func)(void))
{
	builtins **temp;

	temp = root;
	while ((*temp) != NULL)
	{
		temp = &((*temp)->next);
	}

	(*temp) = malloc(sizeof(builtins *));
	if ((*temp) == NULL)
	{
		return (NULL);
	}
	(*temp)->name = name;
	(*temp)->func = func;
	return (*temp);
}