#include "suthread.h"
#include <stdio.h>
suthread_t th_1;
suthread_t th_2;
suthread_t th_3;
suthread_t th_4;
suthread_t th_5;
suthread_t th_6;
suthread_t th_7;

extern struct suthread suthread_main;
extern void suthread_yield_to(suthread_t);

suthread_t array[8];
int ptr = 0;

suthread_t next()
{
    ptr++;
    return array[ptr % 8];
}

void thread(int *p)
{
    for (;;)
    {
        printf("Running: user[%d]\n", *p);
        suthread_yield_to(next());
    }
}

int main()
{
    th_1 = suthread_create(thread, &(int){1}, 4096);
    th_2 = suthread_create(thread, &(int){2}, 4096);
    th_3 = suthread_create(thread, &(int){3}, 4096);
    th_4 = suthread_create(thread, &(int){4}, 4096);
    th_5 = suthread_create(thread, &(int){5}, 4096);
    th_6 = suthread_create(thread, &(int){6}, 4096);
    th_7 = suthread_create(thread, &(int){7}, 4096);

    array[0] = &suthread_main;
    array[1] = th_1;
    array[2] = th_2;
    array[3] = th_3;
    array[4] = th_4;
    array[5] = th_5;
    array[6] = th_6;
    array[7] = th_7;

    while (1)
    {
        puts("Running main");
        suthread_yield_to(next());
    }
    return 0;
}
