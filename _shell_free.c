#include "shell.h"

/**
 * free_double_char - free double char
 * 
 * @opt: pointer address 
 */
void free_double_char( char **opt)
{
	int pos;

	pos = 0;
	while (opt[pos])
	{
		free(opt[pos]);
		pos++;
	}
	free(opt);
}

/**
 * free_builtin_struct - free builtins struct
 * 
 * @opt: pointer address 
 */
void free_builtin_struct( builtins *opt)
{
	if (opt != NULL)
	{
		free_builtin_struct(opt->next);
	}	
	free(opt);
}
