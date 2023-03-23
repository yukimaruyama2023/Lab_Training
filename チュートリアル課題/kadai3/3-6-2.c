#include <stdio.h>
#include <stdint.h>

static __attribute__((always_inline)) uint64_t get_rbp() {
    uint64_t rbp;
    __asm__("movq %%rbp, %0\t\n":"=rm"(rbp));
    return rbp;
}

void f(int x) {
    char w;
    int y; 
    printf("y @ %p\n", &y); 
    printf("rbp y @ %llu\n", get_rbp());
    if(x>0)
        f(x - 1);   
}

int main() {
    int z;
    f(2);
    printf("z @ %p\n", &z);
    printf("rbp z @ %llu\n", get_rbp());
    return 0;
}


