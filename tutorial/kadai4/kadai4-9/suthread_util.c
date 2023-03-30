#include "suthread.h"

extern struct suthread suthread_main;

void insert(suthread_t thread)
{
    suthread_main.prev->next = thread;
    thread->prev = suthread_main.prev;
    thread->next = &suthread_main;
    suthread_main.prev = thread;
}