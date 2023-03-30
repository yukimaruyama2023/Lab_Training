#ifndef _suthread_h_
#define _suthread_h_

#include <stdbool.h>
#include <stddef.h>

struct suthread
{
    char *sp;
    char *stack;
    size_t stack_size;
    void (*thread_func)();
};

typedef struct suthread *suthread_t;
suthread_t suthread_create(void (*thread_func)(), size_t stacksize);
#endif
