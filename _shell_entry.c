#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
/**
 * @brief 
 * 
 * @param buffer 
 * @param buf_len 
 * @return size_t 
 */
int shell_entry(char **buffer, size_t *buf_len)
{
	write(1, "$ ", 2);
	return (getline(buffer, buf_len, stdin));
}
