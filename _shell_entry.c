#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
/**
 * shell_entry - Get our shell entry command
 *
 * @buffer: buffer enter by the user
 * @buf_len: defined buf length
 * Return: size_t
 */
int shell_entry(char **buffer, size_t *buf_len)
{
	int t_mode;

	t_mode =isatty(STDIN_FILENO);
	if (t_mode == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	return (getline(buffer, buf_len, stdin));
}
