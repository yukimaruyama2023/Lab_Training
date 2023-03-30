#include "suthread.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

extern void context_switch(char **, char *);
void start_thread();

struct suthread suthread_main =
    {
        .sp = NULL,
        .stack = NULL,
        .stack_size = 0,
        .thread_func_arg = NULL,
        .thread_func = NULL,
};

static suthread_t current = &suthread_main;

suthread_t suthread_create(void (*thread_func)(void *), void *arg, size_t stack_size)
{
    void *start_add = start_thread;
    suthread_t thread = (suthread_t)calloc(1, sizeof(struct suthread));
    char *stack = (char *)calloc(stack_size, sizeof(char));
    char *sp = &stack[stack_size - 8];
    sp -= (uint64_t)sp % 16;
    // sp = (char *)((uint64_t)sp & ~0xfUL);

    thread->sp = sp;
    *(uint64_t *)(thread->sp) = (uint64_t)start_add;
    thread->sp -= 8 * 7;
    printf("%p\n", thread->stack);
    thread->stack = stack;
    thread->stack_size = stack_size;
    thread->thread_func_arg = arg;
    thread->thread_func = thread_func;

    return thread;
}

void suthread_yield_to(suthread_t next)
{
    if (current == next)
    {
        return;
    }
    suthread_t tmp = current;
    current = next;

    context_switch(&tmp->sp, current->sp);
}

// call function after context_switch
void start_thread()
{
    suthread_t cur = current;
    (*cur->thread_func)(cur->thread_func_arg);
}