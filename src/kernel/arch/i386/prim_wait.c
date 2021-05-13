#include <kernel/prim_wait.h>

// TODO: Fine tune it or find a way to scale it to the cpu or sync to its clock better.
volatile void prim_wait(unsigned int millis)
{
    for(unsigned int i = 0; i < millis; i++)
        for(unsigned int j = 0; j < _PRIM_SECOND; j++);
}