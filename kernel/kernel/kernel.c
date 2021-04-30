#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/IDT.h>

void kernel_main(void) {
	terminal_initialize();

	idt_init();
	printf("GUIDANCE SYSTEMS: CHECK!");
    printf("STARTING PRE-LAUNCH CHECK....");

}


