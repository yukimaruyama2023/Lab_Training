#include <stdio.h>
#include <fcntl.h>

// int main(void) {
//     // int fd;
//     int count = 0;
//     while (open("open", O_RDWR | O_CREAT, 0644) != -1){
//         count++;
//     }
//     perror("");
//     printf("%d\n", count);
//     return 0;
// }

int main(){
    int fd;
    char *fname = "foo.txt";
    int i = 0;

    while((fd = open(fname, O_RDONLY | O_CREAT, 0644)) >= 0){
        i++;
    }
    perror("");
    printf("%d\n", i);
    return 0;
}