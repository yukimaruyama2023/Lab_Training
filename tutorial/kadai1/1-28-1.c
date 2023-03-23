#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf[1024];
    int len;
    // printf("come on\n");
    fd = atoi(argv[1]);
    while((len = read(fd, buf, sizeof(buf))) > 0) {
        printf("%s", buf);
    }
    return 0;
}
