#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;

    if (argc != 2) {
        printf("Enter filename");
        exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        perror("");
        exit(1);
    }
    
    char *c;
    c = (char *)malloc(1024);
    int len;
    int count = 1;
    while((len = read(fd, c, sizeof(c))) > 0) {
        for (int i = 0; i < len; i++) {
            if (*(c + i) == '\n') count++;
        }
    }
    printf("%d\n", count);

    // char c[1024];
    // int len;
    // int count = 1;
    // while((len = read(fd, c, sizeof(c))) > 0) {
    //     for (int i = 0; i < len; i++) {
    //         if (c[i] == '\n') count++;
    //     }
    // }
    // printf("%d\n", count);

    return 0;
}