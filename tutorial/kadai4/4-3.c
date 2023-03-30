#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *sp_1, *sp_2, *stack2;

extern void context_switch(char **current, char *prev);
int main();

void thread_1()
{
    for (;;)
    {
        puts("thread_1 running");
        context_switch(&sp_1, sp_2);
    }
}

void thread_2()
{
    int n = 3;
    char *world = "world";
    printf("hello %s%d\n", world, n);
    for (;;)
    {
        puts("thread_2 running");
        context_switch(&sp_2, sp_1);
    }
}

void init()
{

    sp_1 = (char *)main;
    stack2 = (char *)calloc(4096, sizeof(char));
    sp_2 = &stack2[4095];
    sp_2 -= (uint64_t)sp_2 % 16;
    // sp_2 -= 16;
    *(uint64_t *)sp_2 = (uint64_t)thread_2;
    sp_2 -= 8 * 7;
}
int main()
{
    init();
    thread_1();
    return 0;
}
