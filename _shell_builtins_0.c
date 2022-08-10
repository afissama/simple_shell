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
 * @brief 
 * 
 * @param root 
 * @param name 
 * @param func 
 * @return builtins* 
 */
builtins *add_builtin(builtins **root, char *name, int(*func)(void))
{
	builtins **temp;

	temp = root;
	while ((*temp) != NULL)
	{
		temp = &((*temp)->next);
	}
	
	(*temp) = malloc(sizeof(builtins **));
	(*temp)->name = name;
	(*temp)->func = func;
	return (*temp);
}