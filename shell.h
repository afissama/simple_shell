#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
extern char **environ;
typedef struct s_token
{
    char *token;
    struct s_token *next;
} tokens;
int _strlen(char *s);
tokens *add_token(tokens **root, char *str);
unsigned int list_tokens_len(tokens *root);
int _str_startby(char *s1, char *s2);
char *get_pathenv_var();
char **tokens_to_array(tokens *root);
char *_strcat(char *dest, char *src);
char *check_path(char *command);
int move_to_rigth_dir(char *command);
void shell_exec(char **args, char *prog);
int shell_entry(char **buffer, size_t *buf_len);
char **split_line(char *buffer, char *delimiters);
#endif
