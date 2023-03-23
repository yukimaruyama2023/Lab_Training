#include <stdio.h>
#include <unistd.h>

int main()
{
    char *command = "/bin/ls";
    char *_argv[] = {"ls", "-l", NULL};
    char *envp[] = {NULL};
    execve(command, _argv, envp);
    
    return 0;
}