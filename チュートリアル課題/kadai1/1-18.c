#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
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
    int len;
    int line_num = 2;
    c = (char *)malloc(1024);
    printf("1 ");
    while ((len = read(fd, c, sizeof(c))) > 0) {
        for (int i = 0; i < len; i++) {
            if (*(c + i) == '\n') {
                printf("\n%d ", line_num);
                line_num++;
            }
            else printf("%c", *(c + i));
        }
    }
    printf("\n");

    return 0;
}