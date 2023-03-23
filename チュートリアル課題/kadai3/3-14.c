#include <stdio.h>
#include <stdint.h>

extern void caller_struct();
struct X {
    uint64_t x;
    uint64_t y;
};

void callee_struct(struct X s)
{
    puts("callee_struct:");
    printf("\t.x = % ld\n", s.x);
    printf("\t.y = % ld\n", s.y);
}

int main(){
    caller_struct();
    return 0;
}

