#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

static __attribute__((always_inline)) uint64_t get_rbp() {
    uint64_t rbp;
    __asm__("movq %%rbp, %0\t\n":"=rm"(rbp));
    return rbp;
}

void g() { 
    int x;
    printf("x @ %p\n", &x);
    printf("rbp x @ %lx\n", get_rbp());
}

void f() {
    int y;
    printf("y @ %p\n", &y);
    printf("rbp y @ %lx\n", get_rbp());
    g();
}

int main() {
    int z;
    printf("z @ %p\n", &z);
    printf("rbp main @ %lx\n", get_rbp());
    f();
    return 0;
}

