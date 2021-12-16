#ifndef _INB
#define _INB

#include <common.h>

static inline u8int inb(u8int port)
{
    u8int ret;
    asm volatile("inb %1, %0"
                 : "=a"(ret)
                 : "Nd"(port));
    return ret;
}

#endif