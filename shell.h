#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
extern char **environ;

/**
 * struct s_token - singly token list
 * @token: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked token list node structure
 */
typedef struct s_token
{
	char *token;
	struct s_token *next;
} tokens;

/**
 * struct s_builtins - singly builtins cmd list
 * @name: string - (malloc'ed string)
 * @func: function to execute
 * @next: points to the next node
 *
 * Description: singly linked token list node structure
 */
typedef struct s_builtins
{
	char *name;
	int (*func)(void);
	struct s_builtins *next;
} builtins;

builtins *add_builtin(builtins **root, char *name, int(*func)(void));
int check_builtin(char *command);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int __exit(void);
int __env(void);
tokens *add_token(tokens **root, char *str);
unsigned int list_tokens_len(tokens *root);
int _str_startby(char *s1, char *s2);
char *get_pathenv_var();
char **tokens_to_array(tokens *root);
char *_strcat(char *dest, char *src);
char *check_path(char *command);
int move_to_rigth_dir(char *command);
int shell_exec(char **args, char *prog);
int shell_entry(char **buffer, size_t *buf_len);
char **split_line(char *buffer, char *delimiters);
#endif
