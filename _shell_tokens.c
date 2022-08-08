#include "shell.h"

/**
 * add_token - add token to list
 *
 * @param root
 * @param str
 * @return tokens*
 */
tokens *add_token(tokens **root, char *str)
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
	(*temp_tok)->next = NULL;
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

/**
 * tokens_to_array - convert token struct to array
 *
 * @root: list root
 * Return: array of char*
 */
char **tokens_to_array(tokens *root)
{
	unsigned int tok_size , i;
	char **tok_arr;
	tok_size = list_tokens_len(root);
	i = 0;
	tok_arr = malloc(tok_size *  sizeof(char *));
	while (root != NULL)
	{
		if (root->token != NULL)
		{
			tok_arr[i] = malloc( _strlen(root->token) * sizeof(char));
			tok_arr[i] = root->token;
			i++;
		}
		root = root->next;
	}
	tok_arr[i] = NULL;
	return (tok_arr);
}
