#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main(void);
void f();
void g(int);
void h(int);

typedef struct {
    char c;
    uint64_t *p;
} arrayfunc;

void f() {
    int x = 0xdeadbeef;
    char *p = (char *)(&x) + 100;
    uint64_t *pre_addr = (uint64_t *)p;
    printf("pre_addr:%lx\n", *pre_addr);

    uint64_t *f_func = (uint64_t *)f;
    uint64_t *g_func = (uint64_t *)g;
    uint64_t *h_func = (uint64_t *)h;
    uint64_t *m_func = (uint64_t *)main;
    arrayfunc array[4];
    array[0].c = 'f'; array[0].p = f_func;
    array[1].c = 'g'; array[1].p = g_func;
    array[2].c = 'h'; array[2].p = h_func;
    array[3].c = 'm'; array[3].p = m_func;

    //sort
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
                if (array[i].p > array[j].p) {
                    char tmp = array[i].c;
                    array[i].c = array[j].c;
                    array[j].c = tmp;

                    uint64_t *ttmp = array[i].p;
                    array[i].p = array[j].p;
                    array[j].p = ttmp;
                }
        }
    }
    uint64_t *addr = __builtin_return_address(0);
    for (int i = 0; i < 3; i++) {
        if (array[i].p < addr && addr < array[i+1].p) {
            printf("ret = %lx caller: %c\n", addr, array[i].c);
        }
    }

    // printf("f is %p\n",f_func);
    // printf("g is %p\n",g_func);
    // printf("h is %p\n",h_func);
    // printf("main is %p\n",m_func);
    
}
void g(int x) {
    if (x % 2 == 0) f();
    else f();
}

void h(int x) {
    if (x % 3 == 0) f();
    else if (x % 3 == 1) f();
    else f();
}
int main() {
    int i;
    int r1, r2;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        r1 = rand();
        r2 = rand();
        if (r1 % 2 == 0) {
            printf("calling g(%10d)...\t", r2);
            g(r2); 
        } else {
            printf("calling h(%10d)...\t", r2);
            h(r2); }
    }
    return 0; 
}