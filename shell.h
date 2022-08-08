#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef struct s_token
{
    char *token;
    struct s_token *next;
} tokens;
int _strlen(char *s);
tokens *add_token(tokens **root, char *str);
unsigned int list_tokens_len(tokens *root);
char **tokens_to_array(tokens *root);
void shell_exec(char **args);
int shell_entry(char **buffer, size_t *buf_len);
char** split_line(char *buffer);
#endif
