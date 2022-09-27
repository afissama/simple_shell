#include "shell.h"
/**
 * main - Main shell entry
 *
 * @argc: - nb of args
 * @argv: - arguments
 * Return: int
 */

int main(int argc __attribute__((unused)),
char **argv __attribute__((unused))
)
{
	char *buffer;
	size_t buf_len;
	int t_mode;

	t_mode = isatty(STDIN_FILENO);
	buf_len = 1024;
	buffer = malloc(buf_len * sizeof(char));
	while (shell_entry(&buffer, &buf_len) != -1)
	{
		shell_exec(split_line(buffer, " \n"), argv[0]);
	}
	if (t_mode == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	free(buffer);
	return (0);
}
