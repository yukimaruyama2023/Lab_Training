#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("enter the number\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    _exit(n);
}