#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int pipefd[2];
    pipe(pipefd);

    //parent excutes command1
    if (fork() > 0) {
        dup2(pipefd[1], 1);
        close(pipefd[0]); close(pipefd[1]);
        execlp(argv[1], argv[1], NULL);
    }

    //Child excutes command2
    else{
        dup2(pipefd[0], 0);
        close(pipefd[0]); close(pipefd[1]);
        execlp(argv[2], argv[2], NULL);
    }

    return 0;
}
