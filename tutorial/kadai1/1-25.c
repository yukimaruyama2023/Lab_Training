#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int fib(int);
int nn;
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter number.\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    nn = n;
    printf("fib:%d\n", fib(n));
    return 0;
}

int fib(int n){
    int child[2];
    int status[2];
    int i;
    
    for (i = 0; i < 2 && (child[i] = fork()) > 0; i++) ;
    if (i == 2){
        //parent
        for (int j = 0; j < 2; j++){
            wait(&status[j]);
        }
        if (n == nn) return (status[0] + status[1]);
        else exit(status[0] + status[1]);
    } else {
        //child
        if (n == 0) exit(0);
        else if (n == 1) exit(1);
        else {
            if (i == 0) exit(fib(n-1));
            if (i == 1) exit(fib(n-2));
        }
    }
    
}