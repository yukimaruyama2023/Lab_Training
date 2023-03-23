#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() 
{
    int pipefds[2];
    char *msg = "Hello!";
    char buffer[100];

    pipe(pipefds);
    write(pipefds[1], msg, strlen(msg) + 1); //+1 for \0
    read(pipefds[0], buffer, 100);
    printf("pipe: %s\n",buffer);

    return 0;
}