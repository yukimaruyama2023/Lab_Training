#include "suthread.h"
#include <stdio.h>
suthread_t th_1;
suthread_t th_2;
suthread_t th_3;
suthread_t th_4;
suthread_t th_5;
suthread_t th_6;
suthread_t th_7;
suthread_t th_8;

extern struct suthread suthread_main;
extern void suthread_yield();
extern void suthread_exit();

void thread(int *p)
{
    int i = 1;
    for (;;)
    {
        if (i == 10)
            suthread_exit();
        printf("Running: user[%d]\n", *p);
        suthread_yield();
        i++;
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
    th_8 = suthread_create(thread, &(int){8}, 4096);

    while (1)
    {
        suthread_yield();
    }
    return 0;
}
