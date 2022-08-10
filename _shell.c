#include "shell.h"
/**
 * main - Main shell entry
 *
 * @argc: - nb of args
 * @argv: - arguments
 * Return: int
 */

int main(int argc __attribute__((unused)),
char **argv __attribute__((unused)))
{
	char *buffer;
	size_t buf_len;
	
	buf_len = 1024;
	buffer = malloc(buf_len * sizeof(char));

	while (shell_entry(&buffer, &buf_len) != -1)
	{
		shell_exec(split_line(buffer));
	}
	return (0);
}
