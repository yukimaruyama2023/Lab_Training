#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *pathenv = getenv("PATH");
    printf("%s\n", pathenv);
    // printf("%s\n", argv[1]);
    char *t2[] = {argv[1], NULL};
    char *t3[] = {pathenv, NULL};
    execve(argv[1], t2, t3);
    perror("");
    printf("hoge");
    return 0;
}