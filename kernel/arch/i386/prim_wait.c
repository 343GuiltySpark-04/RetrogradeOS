
#include <kernel/prim_wait.h>

void prim_wait(int time)
{
    volatile int c, d;
    volatile int counter_max = _PRIM_SECOND * time;

        for (c = 1; c <= counter_max; c++)
        for (d = 1; d <= counter_max; d++)
        {
        }
}