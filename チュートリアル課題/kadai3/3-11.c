#include <stdio.h>
#include <stdint.h>

extern void caller_int3();

int64_t callee_int3(int64_t a1, int64_t a2, int64_t a3) {
    puts("callee_int3:");
    printf("\ta1 = %ld\n", a1);
    printf("\ta2 = %ld\n", a2);
    printf("\ta3 = %ld\n", a3);
    return a1 + a2 + a3;
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

// /*not use assembly*/
// int64_t callee_int3(int64_t a1, int64_t a2, int64_t a3) {
//     puts("callee_int3:");
//     printf("\ta1 = %ld\n", a1);
//     printf("\ta2 = %ld\n", a2);
//     printf("\ta3 = %ld\n", a3);
//     return a1 + a2 + a3;
// }

// void check_ret(int64_t r) {
//     puts("check_ret:");
//     printf("\tret = %ld\n", r);
// }


// void caller_int3(){
//     int64_t x = 111;
//     int64_t y = 222;
//     int64_t z = 333;
    
//     int64_t ret;
//     ret = callee_int3(x, y, z);
//     check_ret(ret + 1000);

// }
// int main()
// {
//     caller_int3();
//     return 0;
// }

