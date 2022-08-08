#include "shell.h"

/**
 * add_token - add token to list
 * 
 * @param root 
 * @param str 
 * @return tokens* 
 */
tokens *add_token(tokens **root, char str)
{
	tokens **temp_tok;

	temp_tok = root;
	while ((*temp_tok) != NULL)
	{
		temp_tok = &((*temp_tok)->next);
	}
	(*temp_tok) = malloc(sizeof(tokens *));
	if ((*temp_tok) == NULL)
	{
		return (NULL);
	}
	(*temp_tok)->token = str;
	return (*temp_tok);
}

/**
 * list_tokens_len - get tokens list length
 * 
 * @root: tokens list root element 
 * Return: size of the token list
 */
unsigned int list_tokens_len(tokens *root)
{
	if (root == NULL)
	{
		return (0);
	}
	return (1 + list_tokens_len(root->next));
}
