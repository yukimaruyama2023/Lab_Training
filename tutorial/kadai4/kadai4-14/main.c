#include "suthread.h"
#include <stdio.h>
#include <stdlib.h>
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
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Running: user[%d]\n", *p);
        suthread_yield();
    }
}

int add(int x, int y)
{
    return x + y;
}

int main()
{
    th_1 = suthread_create(thread, &(int){1}, 9000);
    th_2 = suthread_create(thread, &(int){2}, 9000);
    th_3 = suthread_create(thread, &(int){3}, 9000);
    th_4 = suthread_create(thread, &(int){4}, 9000);
    th_5 = suthread_create(thread, &(int){5}, 9000);
    th_6 = suthread_create(thread, &(int){6}, 9000);
    th_7 = suthread_create(thread, &(int){7}, 9000);
    th_8 = suthread_create(thread, &(int){8}, 9000);
    while (1)
    {
        suthread_yield();
    }
    return 0;
}
