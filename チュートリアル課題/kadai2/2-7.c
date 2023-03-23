#include <stdio.h> 
// int a[10];
// int *p;

short int a[10];
short int *p;



int main() {
    int i;

    // for (i = 0; i < sizeof(a) / sizeof(int); i++)
    for (i = 0; i < sizeof(a) / sizeof(short int); i++)
    a[i] = i;
    a[10] = 10;
    p = a;
    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(int));
    printf("&p = %p\n", &p);
    printf(" p = %p | &a[0] = %p\n", p, &a[0]);
    p += 5;
    printf("*p = %11d | a[5] = %11d |*(a+5) = %11d\n", *p, a[5], *(a+5));
    printf(" p = %p |&a[5] = %p | (a+5) = %p\n", p, &a[5], (a+5));
    return 0;


}

// // void init_array(int a[]) {
// //     printf("%d\n", sizeof(a));
// //     printf("%d\n", sizeof(int *));
// //     for (int i = 0; i < sizeof(a) / sizeof(int); i++)
// //         a[i] = i;
// // }

// int main() {
//     int i;

//     init_array(a);
//     p = a;
//     // printf("%lu\n", sizeof(a));
//     // printf("%lu\n", sizeof(int));
//     printf("&p = %p\n", &p);
//     printf(" p = %p | &a[0] = %p\n", p, &a[0]);
//     p += 5;
//     printf("*p = %11d | a[5] = %11d |*(a+5) = %11d\n", *p, a[5], *(a+5));
//     printf(" p = %p |&a[5] = %p | (a+5) = %p\n", p, &a[5], (a+5));
//     return 0;
// }