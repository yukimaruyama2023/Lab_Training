#include "suthread.h"
#include <stdint.h>
#include <stdlib.h>

struct suthread suthread_main =
    {
        .sp = NULL,
        .stack = NULL,
        .stack_size = 0,
        .thread_func = NULL,
};
suthread_t suthread_create(void (*thread_func)(), size_t stack_size)
{
    suthread_t thread = (suthread_t)calloc(1, sizeof(struct suthread));
    char *stack = (char *)calloc(stack_size, sizeof(char));
    char *sp = &stack[4095];
    sp -= (uint64_t)sp % 16;

    thread->sp = sp;
    *(uint64_t *)(thread->sp) = (uint64_t)thread_func;
    thread->stack = stack;
    thread->stack_size = stack_size;
    thread->thread_func = thread_func;

    thread->sp -= 8 * 7;

    return thread;
}

// void suthread_yield_to(suthread_t next)
// {
// }