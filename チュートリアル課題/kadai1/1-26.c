#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid;

    if ((pid = fork()) > 0) {
        //parent: sleep forever
        sleep(1000);
    }
    else if (pid == 0) {
        // Child: exit immediately
        exit(1);
    }
    else {
        perror("fork");
        exit(1);
    }
    return 0;
}