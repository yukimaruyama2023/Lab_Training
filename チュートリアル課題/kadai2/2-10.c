#include <stdio.h>

struct bar {
       char a;
       int b;
       char c;
       double d;
} bar;

int main() {
    printf("sizeof(double) = %lu, sizeof(struct bar) = %lu\n",
                      sizeof(double), sizeof(struct bar));
    printf(
       "&bar = %p, &bar.a = %p, &bar.b = %p, &bar.c = %p, &bar.d = %p\n",
       &bar, &bar.a, &bar.b, &bar.c, &bar.d);
    return 0;
}