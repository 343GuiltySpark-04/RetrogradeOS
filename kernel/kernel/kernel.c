#include <stdio.h>
#include <kernel/tty.h>





static inline unsigned long read_cr0(void)
{
    unsigned long val;
    asm volatile ( "mov %%cr0, %0" : "=r"(val) );
    return val;
}

void kernel_main(void) {
	terminal_initialize();

	int aif = 1;

	if (aif == 1){

		printf("TEST 1");

	}else{

		printf("TEST 2");
	}

	//printf("GUIDANCE SYSTEMS: CHECK!\n");
   // printf("STARTING PRE-LAUNCH CHECK....\n");

	printf(read_cr0);

	


  

}


