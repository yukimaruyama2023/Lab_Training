#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

static __attribute__((always_inline)) uint64_t get_rbp() {
    uint64_t rbp;
    __asm__("movq %%rbp, %0\t\n":"=rm"(rbp));
    return rbp;
}

void f(int);

void g(int x) {
    char w;
    double y;
    printf("y @ %p\n", &y);
    printf("rbp y @ %lx\n", get_rbp());
    if (x > 0)
        f(x);
}

void f(int x) {
    char z;
    printf("z @ %p\n", &z);
    printf("rbp z @ %lx\n", get_rbp());
    g(x - 1);
}

int main() {
    int w;
    f(2);
    printf("w @ %p\n", &w);
    printf("rbp w @ %lx\n", get_rbp());
    return 0;
}

