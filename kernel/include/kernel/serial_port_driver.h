#ifndef SERIAL_PORT_DRIVER_H
#define SERIAL_PORT_DRIVER_H

#include <common.h>

int init_serial();

char read_serial_COM1();

void write_serial_COM1(char a);

void write_debug_code(char a, char b, char c);

#endif