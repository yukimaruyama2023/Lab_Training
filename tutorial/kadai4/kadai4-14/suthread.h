#ifndef _suthread_h_
#define _suthread_h_

#include <stdbool.h>
#include <stddef.h>

enum suthread_state
{
    SUTHREAD_READY,
    SUTHREAD_RUNNING,
    SUTHREAD_TERMINATING,
};

struct suthread
{
    char *sp;
    char *stack;
    size_t stack_size;
    void *thread_func_arg;
    void (*thread_func)();
    volatile enum suthread_state state;
    struct suthread *prev, *next;
};

typedef struct suthread *suthread_t;
suthread_t suthread_create(void (*thread_func)(), void *arg, size_t stacksize);
#endif
