#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{   
    int fd1, fd2;
    char c;

    if (argc < 3) {
        printf("Enter two files.\n");
        exit(1);
    }

    if (getopt(argc, argv, "i") > 0) {
        if((fd1 = open(argv[2], O_RDONLY)) < 0) {
            perror("While opening sourcre file");
            exit(1);
        }
        if ((fd2 = open(argv[3], O_WRONLY )) < 0) {
            perror("While opening destination file");
            exit(1);
        }
        int len;
        while((len = read(fd1, &c, sizeof(c))) > 0) {
        
            write(fd2, &c, len);
            // printf("%d\n", len);
        }
    } else {
        if((fd1 = open(argv[1], O_RDONLY)) < 0) {
            perror("While opening sourcre file");
            exit(1);
        }
        if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644)) < 0) {
            perror("While opening destination file");
            exit(1);
        }
        int len;
        while((len = read(fd1, &c, sizeof(c))) > 0) {
        
            write(fd2, &c, len);
            
        }
    
    }
    return 0;
    
}
// int main(int argc, char *argv[])
// {   
//     int fd1, fd2;
//     char c;
//     char *source, *dest;

//     if (argc < 3) {
//         printf("Enter two files.\n");
//         exit(1);
//     }

//     if (getopt(argc, argv, "i") > 0) {
//         source = argv[2];
//         dest = argv[3];
//     } else {
//         source = argv[1];
//         dest = argv[2];
        
//     }
//     if ((fd1 = open(source, O_RDONLY)) < 0) {
//         perror("While opening sourcre file");
//         exit(1);
//     }
//     if ((fd2 = open(dest, O_WRONLY )) < 0) {
//         perror("While opening destination file");
//         exit(1);
//     }
//     int len;
//     while((len = read(fd1, &c, sizeof(c))) > 0) {
    
//         write(fd2, &c, len);
//         // printf("%d\n", len);
//     }
    
    
//     return 0;
    
// }
