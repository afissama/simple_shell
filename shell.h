#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>

typedef struct s_token
{
    char *token;
    struct s_token *next;
} tokens;
tokens *add_token(tokens **root, char str);
unsigned int list_tokens_len(tokens *root);
char **tokens_to_array(tokens *root);
int shell_entry(char **buffer, size_t *buf_len);
#endif
