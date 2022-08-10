#include "shell.h"
#include <unistd.h>
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
