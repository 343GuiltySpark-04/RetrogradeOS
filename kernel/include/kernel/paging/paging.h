

/* source code from https://github.com/LittleCodingFox/ToastOS/blob/master/src/low-level/paging/Paging.hpp 
with some modifactions fo x86 */

#pragma once
#ifndef PAGING_H

#define HIGHER_HALF_MEMORY_OFFSET 0xFFFF800000000000
#define HIGHER_HALF_KERNEL_MEMORY_OFFSET 0xFFFFFFFF80000000

#define PAGE_FLAG_MASK (0xFFF | (1ull << 63))
#define PAGE_ADDRESS_MASK (~(PAGE_FLAG_MASK))

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

inline uint32_t TranslateToHighHalfMemoryAddress(uint32_t physicalAddress)
{
    return physicalAddress + HIGHER_HALF_MEMORY_OFFSET;
}

inline uint32_t TranslateToPhysicalMemoryAddress(uint32_t virtualAddress)
{
    return virtualAddress - HIGHER_HALF_MEMORY_OFFSET;
}

inline uint32_t TranslateToKernelPhysicalMemoryAddress(uint32_t virtualAddress)
{
    return virtualAddress - HIGHER_HALF_KERNEL_MEMORY_OFFSET;
}

inline uint32_t TranslateToKernelMemoryAddress(uint32_t virtualAddress)
{
    return virtualAddress + HIGHER_HALF_KERNEL_MEMORY_OFFSET;
}

inline bool IsHigherHalf(uint32_t physicalAddress)
{
    return physicalAddress >= HIGHER_HALF_MEMORY_OFFSET;
}

inline bool IsKernelHigherHalf(uint32_t physicalAddress)
{
    return physicalAddress >= HIGHER_HALF_KERNEL_MEMORY_OFFSET;
}

enum PagingFlag
{
    PAGING_FLAG_PRESENT = (1ull << 0),
    PAGING_FLAG_WRITABLE = (1ull << 1),
    PAGING_FLAG_USER_ACCESSIBLE = (1ull << 2),
    PAGING_FLAG_LARGER_PAGES = (1ull << 7),
    PAGING_FLAG_NO_EXECUTE = (1ull << 63),
};

typedef struct 
{
    uint32_t p4Offset;
    uint32_t pdpOffset;
    uint32_t pdOffset;
    uint32_t ptOffset;
} PageTableOffset;

struct PageTable
{
    uint32_t entries[512];
} __attribute__((aligned(0x1000)));

PageTableOffset VirtualAddressToOffsets(void *address);
void *OffsetToVirtualAddress(PageTableOffset offset);

#endif