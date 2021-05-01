#include <stdio.h>
#include <stdbool.h>
#include <kernel/check_sti.h>
#include <kernel/tty.h>
#include <stdlib.h>

void kernel_main(void)
{
	terminal_initialize();

	bool check_interrupts = are_interrupts_enabled();

	if (check_interrupts == true)
	{

		printf("INTERRUPTS SUBSYSTEM: CHECK!");
	}
	else if (check_interrupts == false)
	{
		printf("ERROR: PROBLEM WITH ITERRUPTS SUBYSTEM! ABORT LAUNCH!");
		abort();
	}

	printf("GUIDANCE SYSTEMS: CHECK!");
	printf("STARTING PRE-LAUNCH CHECK....");
}
