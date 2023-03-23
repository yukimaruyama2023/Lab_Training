#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //open destfile
    int fd;
    if ((fd = open(argv[2], O_WRONLY | O_CREAT, 0644)) < 0){
        perror(argv[2]);
        exit(1);
    }

    //destfile:from fd to stdout
    dup2(fd, 1);
    close(fd);

    char *_argv[] = {argv[1], NULL};
    // char *_env[] = {PATH, NULL};
    // char *_argv[] = {"ls", "-l", NULL};
    // execve(argv[1], _argv, NULL);
    execlp(argv[1], argv[1], NULL);
    // execve("/bin/ls", _argv, NULL);
    // execve("/bin/ls", _argv, NULL);
    printf("hey");
    return -1;
}