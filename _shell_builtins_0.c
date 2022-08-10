#include "shell.h"
/**
 * __exit - exit the shell
 *
 * @return int
 */
void __exit()
{
	exit(0);
}

/**
 * add_builtin - add new builtin to the end of list
 * 
 * @root: root elem
 * @name: comman name
 * @func: fucntion to execute
 * Return: a builtins* 
 */
builtins *add_builtin(builtins **root, char *name, void(*func)(void))
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