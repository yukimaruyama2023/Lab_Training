#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//original code
int main() 
{
    int fd; 
    if ((fd = open("sample2.txt", O_WRONLY | O_APPEND)) < 0) {
        perror("sample2.txt");
        exit(1);
    }
    write(fd, "C", 1);
    lseek(fd, 0, SEEK_SET);
    write(fd, "B", 1);
    close(fd);
    return 0;
}

// //modified code
// int main() 
// {
//     int fd; 
//     if ((fd = open("sample2.txt", O_WRONLY)) < 0) {
//         perror("sample2.txt");
//         exit(1);
//     }
//     lseek(fd, 0, SEEK_END);
//     write(fd, "C", 1);
//     lseek(fd, 0, SEEK_SET);
//     write(fd, "B", 1);
//     close(fd);
//     return 0;
// }