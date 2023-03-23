#include <stdio.h>
#include <stdint.h>

extern void caller_struct2();

struct Y {
    uint64_t x;
    uint64_t y;
    uint64_t z;
    uint64_t w;
};

void callee_struct2(struct Y s)
{
    puts("callee_struct2:");
    printf("\t.x = %ld\n",s.x);
    printf("\t.y = %ld\n",s.y);
    printf("\t.z = %ld\n",s.z);
    printf("\t.w = %ld\n",s.w);
}

// void caller_struct2(){
//     struct Y s = {
//         .x = 111,
//         .y = 222,
//         .z = 333,
//         .w = 444,
//     };
//     callee_struct2(s);
// }
int main(){
    caller_struct2();
    return 0;
}

