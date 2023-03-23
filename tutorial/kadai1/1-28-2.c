#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *str_fd;
    char num;
    fd = open("test.txt", O_RDONLY);
    // sprintf(str_fd, "%d", fd);
    num = fd + '0';
    char *command = "./1-28-1";
    char *_argv[] = {"./1-28-1", &num, NULL};
    char *envp[] = {NULL};

    execve(command, _argv, envp);
}