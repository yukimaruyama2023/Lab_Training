#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //open sourcefile
    int fd;
    if ((fd = open(argv[2], O_RDONLY)) < 0){
        perror(argv[2]);
        exit(1);
    }

    //sourcefile's descriptor:from fd to stdin
    dup2(fd, 0);
    close(fd);

    // char *_argv[] = {argv[1], NULL};
    execlp(argv[1], argv[1], NULL);
    printf("hey");
    return -1;
}