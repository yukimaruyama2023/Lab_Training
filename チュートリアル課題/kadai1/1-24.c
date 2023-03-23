#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <sys/wait.h>
#include <stdlib.h>


// int main() 
// {
//     int first, second, third, fourth;
//     int status1, status2, status3, status4;
//     if ((first = fork()) > 0){
//         //first parent
//         printf()
//         wait(&status1);
//         if (WIFEXITED(status1)) {
//             printf("Child's pid is %d and status is %d\n", first, WEXITSTAUS(status1));
//         }
//         if ((second = fork()) > 0 ) {
//             //socond parent
//             if ((third = fork()) > 0) {
//                 if ((fourth) > 0) {

//                 }
//             } else {
//                 //second child
//                 sleep(rand());
//                 exit(2);
//             }
//         }
//     } else  {
//         //first child
//         sleep(rand());
//         exit(1);
//     }
    
// }

int main() {
    int pid[4];
    int child_pid[4];
    int child_status[4];
    int i;
    for (i = 0; i < 4 && (pid[i] = fork()) > 0; i++){
        printf("Child's number is %d and pid is %d\n", i+1, pid[i]);
    }
    if (i == 4) {
        //parent
        for (int j = 0; j < 4; j++){
            child_pid[i] = wait(&child_status[i]);
            printf("Return: Child pid is %d and status is %d\n", child_pid[i], WEXITSTATUS(child_status[i]));
        }
    } else {
        //child
        sleep(rand() % 10);
        exit(i+1);
    }
    return 0;
}