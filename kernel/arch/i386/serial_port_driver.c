#define PORT_COM1 0x3f8

#include <common.h>

int init_serial()
{
    outb(PORT_COM1 + 1, 0x00); // Disable all interrupts
    outb(PORT_COM1 + 3, 0x80); // Enable DLAB (set baud rate divisor)
    outb(PORT_COM1 + 0, 0x03); // Set divisor to 3 (lo byte) 38400 baud
    outb(PORT_COM1 + 1, 0x00); //                  (hi byte)
    outb(PORT_COM1 + 3, 0x03); // 8 bits, no parity, one stop bit
    outb(PORT_COM1 + 2, 0xC7); // Enable FIFO, clear them, with 14-byte threshold
    outb(PORT_COM1 + 4, 0x0B); // IRQs enabled, RTS/DSR set
    outb(PORT_COM1 + 4, 0x1E); // Set in loopback mode, test the serial chip
    outb(PORT_COM1 + 0, 0xAE); // Test serial chip (send byte 0xAE and check if serial returns same byte)

    // Check if serial is faulty (i.e: not same byte as sent)
    if (inb(PORT_COM1 + 0) != 0xAE)
    {
        return 1;
    }

    // If serial is not faulty set it in normal operation mode
    // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
    outb(PORT_COM1 + 4, 0x0F);
    return 0;
}

int serial_received_COM1()
{

    return inb(PORT_COM1 + 5) & 1;
}

char read_serial_COM1()
{

    while (serial_received_COM1() == 0)
        ;

    return inb(PORT_COM1);
}

int is_xmit_empty_COM1()
{

    return inb(PORT_COM1 + 5) & 0x20;
}

void write_serial_COM1(char a)
{

    while (is_xmit_empty_COM1() == 0)
        ;

    outb(PORT_COM1, a);
}

void write_debug_code(char a, char b, char c)
{

    while (is_xmit_empty_COM1() == 0)
        ;

    outb(PORT_COM1, '*');
    outb(PORT_COM1, a);
    outb(PORT_COM1, b);
    outb(PORT_COM1, c);
    outb(PORT_COM1, '*');
}