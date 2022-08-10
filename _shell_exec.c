#include "shell.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * shell_exec - execute given command
 *
 * @args: passing argumnents
 * @prog: the program name
 */
void shell_exec(char **args, char *prog)
{
	pid_t child_pid;
	int status;

	if (args[0] != NULL)
	{
		if (check_builtin(args[0]) == -1)
		{
			args[0] = check_path(args[0]);
			if (args[0] == NULL)
			{
				perror(prog);
			}

			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				exit(1);
			}

			if (!child_pid)
			{
				if (execve(args[0], args, environ) == -1)
				{
					perror(prog);
				}
			}
			else
			{
				wait(&status);
			}
		}
	}
}

/**
 * check_path - check the real path
 * if it exist
 *
 * @command: Entry
 * Return: char*
 */
char *check_path(char *command)
{
	char *path;
	char **directories;
	char *tmp_dir;
	int pos;
	struct stat st;

	if (command == NULL)
		return (NULL);
	if (stat(command, &st) == 0)
		return (command);

	path = get_pathenv_var();
	pos = 0;
	if (path != NULL)
	{
		directories = split_line(path, ":");
		while (directories[pos])
		{
			tmp_dir = _strcat(directories[pos], "/");
			if (stat(_strcat(tmp_dir, command), &st) == 0)
			{
				return (_strcat(tmp_dir, command));
			}
			pos++;
		}
	}
	return (NULL);
}

/**
 * check_builtin - check if command is builtin
 *
 * @command: command inserted
 * Return: -1 on fail
 */
int check_builtin(char *command)
{
	builtins *builtin_;

	builtin_ = NULL;
	add_builtin(&builtin_, "exit", __exit);
	add_builtin(&builtin_, "env", __env);
	while (builtin_ != NULL)
	{
		if (_strcmp(command, builtin_->name) == 0)
		{
			return (builtin_->func());
		}
		builtin_ = builtin_->next;
	}

	return (-1);
}
