#include "shell.h"
#include <string.h>
/**
 * split_line - split the buffer according to delimiters
 *
 * @buffer: line
 * Return: char**
 */
char** split_line(char *buffer)
{
	tokens *_token;
	char *cur_tok;

	_token = malloc(sizeof(tokens *));
	cur_tok = strtok(buffer, " ");
	while (cur_tok != NULL)
	{
		add_token(&_token, cur_tok);
		cur_tok = strtok(NULL, " ");
	}

	return (tokens_to_array(_token));
}