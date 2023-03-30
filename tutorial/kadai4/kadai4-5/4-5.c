#include "suthread.h"
suthread_t th_1;
suthread_t th_2;

extern struct suthread suthread_main;
void thread_1()
{
    for (;;)
    {
        puts("Thread1");
        context_switch(&th_1->sp, th_2->sp);
    }
}

void thread_2()
{
    for (;;)
    {
        puts("Thread2");
        context_switch(&th_2->sp, suthread_main.sp);
    }
}

int main()
{
    th_1 = suthread_create(thread_1, 4096);
    th_2 = suthread_create(thread_2, 4096);
    while (1)
    {
        puts("Main");
        context_switch(&suthread_main.sp, th_1->sp);
    }
    return 0;
}