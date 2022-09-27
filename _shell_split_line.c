#include "shell.h"
#include <string.h>
/**
 * split_line - split line according to its delimiters
 *
 * @buffer: buffer to execute
 * @delimiters: delimiters for split
 * Return: char**
 */
char **split_line(char *buffer, char *delimiters)
{
	tokens *_token;
	char *cur_tok;
	char **tokarr;

	if (buffer == NULL || delimiters == NULL)
	{
		return (NULL);
	}

	_token = malloc(sizeof(tokens *));
	cur_tok = strtok(buffer, delimiters);
	while (cur_tok != NULL)
	{
		add_token(&_token, cur_tok);
		cur_tok = strtok(NULL, delimiters);
	}
	free(cur_tok);
	tokarr = tokens_to_array(_token);
	free(_token);
	return (tokarr);
}
