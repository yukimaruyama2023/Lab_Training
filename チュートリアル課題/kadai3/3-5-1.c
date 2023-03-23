#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void g() { 
    int x;
    printf("x @ %p\n", &x);
}

void f() {
    int y;
    printf("y @ %p\n", &y);
    g();
}

int main() {
    int z;
    printf("z @ %p\n", &z);
    f();
    return 0;
}