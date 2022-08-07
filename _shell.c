#include "shell.h"
/**
 * main - Main shell entry
 *
 * @argc - nb of args
 * @argv - arguments
 * Return: int
 */

int main(void)
{
	char *buffer;
	size_t buf_len;

	buf_len = 1024;
	buffer = malloc(buf_len * sizeof(char));

    while (shell_entry(&buffer, &buf_len) != -1)
    {
        printf("%s", buffer);
    }
	return 0;
}
