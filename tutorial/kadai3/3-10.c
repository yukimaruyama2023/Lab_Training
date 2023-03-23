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
int main()
{
    caller_int3();
    return 0;
}