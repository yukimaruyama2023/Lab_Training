#include <stdio.h>
#include <stdint.h>

extern void caller_int3();

int64_t callee_int3(int64_t a1, int64_t a2, int64_t a3, int64_t a4, int64_t a5, int64_t a6, int64_t a7) {
    puts("callee_int3:");
    printf("\ta1 = %ld\n", a1);
    printf("\ta2 = %ld\n", a2);
    printf("\ta3 = %ld\n", a3);
    printf("\ta4 = %ld\n", a4);
    printf("\ta5 = %ld\n", a5);
    printf("\ta6 = %ld\n", a6);
    printf("\ta7 = %ld\n", a7);
    return a1 + a2 + a3 + a4 + a5 + a6 + a7;
}

void check_ret(int64_t r) {
    puts("check_ret:");
    printf("\tret = %ld\n", r);
}

int main()
{
    caller_int3();
    return 0;
}

// /*not use assembly file*/

// int64_t callee_int3(int64_t a1, int64_t a2, int64_t a3, int64_t a4, int64_t a5, int64_t a6, int64_t a7, int64_t a8) {
//     puts("callee_int3:");
//     printf("\ta1 = %ld\n", a1);
//     printf("\ta2 = %ld\n", a2);
//     printf("\ta3 = %ld\n", a3);
//     printf("\ta4 = %ld\n", a4);
//     printf("\ta5 = %ld\n", a5);
//     printf("\ta6 = %ld\n", a6);
//     printf("\ta7 = %ld\n", a7);
//     printf("\ta8 = %ld\n", a8);
//     return a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;
// }

// void check_ret(int64_t r) {
//     puts("check_ret:");
//     printf("\tret = %ld\n", r);
// }

// void caller_int3(){
//     uint64_t x = callee_int3(111, 222, 333, 444, 555, 666, 777, 888);
//     check_ret(x);
// }

// int main()
// {
//     caller_int3();
//     return 0;
// }