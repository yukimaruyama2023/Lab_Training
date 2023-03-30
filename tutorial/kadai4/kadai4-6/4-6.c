#include "suthread.h"
#include <stdio.h>
suthread_t th_1;

extern struct suthread suthread_main;
extern void suthread_yield_to(suthread_t);
void thread_1(int *p)
{
    for (;;)
    {
        printf("thread 1 argment is %d\n", *p);
        // context_switch(&th_1->sp, th_2->sp);
        // context_switch(&th_1->sp, suthread_main.sp);
        suthread_yield_to(&suthread_main);
    }
}

int main()
{
    // int n = 3;
    th_1 = suthread_create(thread_1, &(int){1}, 4096);

    while (1)
    {
        puts("Main");
        suthread_yield_to(th_1);
    }
    return 0;
}