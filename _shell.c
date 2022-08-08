#include "shell.h"
/**
 * main - Main shell entry
 *
 * @argc - nb of args
 * @argv - arguments
 * Return: int
 */

int main(int argc, char **argv, char **envp)
{
	char *buffer;
	char **tokens;
	size_t buf_len;

	buf_len = 1024;
	buffer = malloc(buf_len * sizeof(char));

    while (shell_entry(&buffer, &buf_len) != -1)
    {
        printf("%s", buffer);
		free(buffer);
    }
	write(stdin, "\n", 1);
	return 0;
}
