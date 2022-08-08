#include "shell.h"
#include <unistd.h>

/**
 * shell_exec - execute given command
 * 
 * @args: passing argumnents 
 */
void shell_exec(char **args)
{
    if (execve(args[0], args, NULL) != -1)
    {
        
    }
    else
    {
        perror(args[0]);
    }
}