#ifndef _PRIM_WAIT
#define _PRIM_WAIT
#define _PRIM_SECOND 22308

#include <stdio.h>


     volatile void prim_wait(int time){

    int c, d;
    int counter_max = _PRIM_SECOND * time;

        for (c = 1; c <= counter_max; c++)
        for (d = 1; d <= counter_max; d++)
        {}



}

#endif