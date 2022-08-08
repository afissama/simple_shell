#include <stdlib.h>
#include <stdio.h>
/**
 * @brief 
 * 
 * @param buffer 
 * @param buf_len 
 * @return size_t 
 */
int shell_entry(char **buffer, size_t *buf_len)
{
	write(stdin, "$ ", 2);
	return (getline(buffer, buf_len, stdin));
}
