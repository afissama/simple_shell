#include "shell.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * shell_exec - execute given command
 *
 * @args: passing argumnents
 */
void shell_exec(char **args, char *prog)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}

	if (!child_pid)
	{
		args[0] = check_path(args[0]);
		if (execve(args[0], args, NULL) == -1)
		{
			perror(prog);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * @brief 
 * 
 * @param command 
 * @return char* 
 */
char* check_path(char *command)
{
	char *path;
	char **directories;
	char *tmp_dir;
	int pos;
	struct stat st;

	if (stat(command, &st) == 0)
	{
		return (command);
	}
	
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
	return (command);
}
