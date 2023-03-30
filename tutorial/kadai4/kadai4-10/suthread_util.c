#include <stdio.h>
#include <stdlib.h>
#include "suthread.h"

extern struct suthread suthread_main;

void insert(suthread_t thread)
{
    suthread_main.prev->next = thread;
    thread->prev = suthread_main.prev;
    thread->next = &suthread_main;
    suthread_main.prev = thread;
}

void release(suthread_t thread)
{
    thread->prev->next = thread->next;
    thread->next->prev = thread->prev;
    free(thread);
    printf("Exit: user %d\n", *(int *)thread->thread_func_arg);
}