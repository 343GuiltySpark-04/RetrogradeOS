#ifndef SERIAL_PORT_DRIVER_H
#define SERIAL_PORT_DRIVER_H

#include <common.h>

char read_serial_COM1();

void write_serial_COM1(char a);

void write_debug_serial(char a, char b, char c);

#endif