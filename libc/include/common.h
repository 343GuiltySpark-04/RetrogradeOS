#ifndef COMMON_H
#define COMMON_H

// standard typedefs

typedef unsigned int u32int;
typedef int s32int;
typedef unsigned short u16int;
typedef short s16int;
typedef unsigned char u8int;
typedef char s8int;
typedef unsigned long u64int;
typedef long s64int;

void outb(u16int port, u8int value);
u8int inb(u16int port);

#endif