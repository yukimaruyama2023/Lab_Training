#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// int main()
// {
//     char a = 'a';
//     int fd;
//     clock_t begin, end;
//     if ((fd = open("foo.txt", O_WRONLY | O_CREAT, 0644)) < 0) {
//         perror("");
//         exit(1);
//     }
//     begin = clock();
//     for (int i = 0; i < 8 * 1024 * 1024; i++) {
//         write(fd, &a, sizeof(a));
//     }
//     end = clock();

//     printf("Time = %lf[s]\n", (double)(end - begin) / CLOCKS_PER_SEC);
//     return 0;
// }
// int main()
// {
//     int fd;
//     printf("a");
//     char a[84];
//     printf("b"); 
//     if ((fd = open("foo.txt", O_WRONLY | O_CREAT, 0644)) < 0) {
//         perror("");
//         exit(1);
//     }
//     for (int i = 0; i < 8 ; i++) {
//         a[i] = 'a';
//     }
//     write(fd, a, sizeof(a));
    
//     return 0;
// }

int main()
{
    char a = 'a';
    FILE *fp;
    clock_t begin, end;
    if ((fp = fopen("foo.txt", "w")) < 0) {
        perror("");
        exit(1);
    }
    begin = clock();
    for (int i = 0; i < 8 * 1024 * 1024; i++) {
        fputc(a, fp);
    }
    end = clock();
    printf("Time = %lf[s]\n", (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}
