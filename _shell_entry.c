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
	write(1, "$ ", 2);
	return (getline(buffer, buf_len, stdin));
}
