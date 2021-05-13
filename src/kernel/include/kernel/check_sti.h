#ifndef _CHECK_SLI
#define _CHECK_SLI

#include <stdbool.h>

static inline bool are_interrupts_enabled()
{
    unsigned long flags;
    asm volatile("pushf\n\t"
                 "pop %0"
                 : "=g"(flags));
    return flags & (1 << 9);
}

#endif