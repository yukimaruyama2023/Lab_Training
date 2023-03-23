#include <stdio.h>
#include <stdint.h>

extern void caller_struct2();

struct Y
{
    int64_t x;
    int64_t y;
    int64_t z;
    int64_t w;
};

struct Y callee_ret_struct2()
{
    struct Y s = {
        .x = 123,
        .y = 456,
        .z = 789,
        .w = 321

    };
    puts("callee_ret_struct:");
    printf("\t.x = %ld\n", s.x);
    printf("\t.y = %ld\n", s.y);
    printf("\t.z = %ld\n", s.z);
    printf("\t.w = %ld\n", s.w);
    return s;
}

void callee_struct2(struct Y s)
{
    puts("callee_struct2:");
    printf("\t.x = %ld\n", s.x);
    printf("\t.y = %ld\n", s.y);
    printf("\t.z = %ld\n", s.z);
    printf("\t.w = %ld\n", s.w);
}

// void caller_struct2() {
//     struct Y s = callee_ret_struct2();
//     s.x += 100;
//     s.y += 100;
//     s.z += 100;
//     s.w += 100;
//     callee_struct2(s);
// }

int main()
{
    caller_struct2();
    return 0;
}