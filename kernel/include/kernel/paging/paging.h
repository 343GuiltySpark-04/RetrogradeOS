

/* sourcce code from https://github.com/LittleCodingFox/ToastOS/blob/master/src/low-level/paging/Paging.hpp 
with some modifactions fo x86 */

#pragma once
#ifndef PAGING_H

#define HIGHER_HALF_MEMORY_OFFSET 0xFFFF800000000000
#define HIGHER_HALF_KERNEL_MEMORY_OFFSET 0xFFFFFFFF80000000

#define PAGE_FLAG_MASK (0xFFF | (1ull << 63))
#define PAGE_ADDRESS_MASK (~(PAGE_FLAG_MASK))

#include <stdint.h>

inline uint64_t TranslateToHighHalfMemoryAddress(uint64_t physicalAddress)
{
    return physicalAddress + HIGHER_HALF_MEMORY_OFFSET;
}

inline uint64_t TranslateToPhysicalMemoryAddress(uint64_t virtualAddress)
{
    return virtualAddress - HIGHER_HALF_MEMORY_OFFSET;
}

inline uint64_t TranslateToKernelPhysicalMemoryAddress(uint64_t virtualAddress)
{
    return virtualAddress - HIGHER_HALF_KERNEL_MEMORY_OFFSET;
}

inline uint64_t TranslateToKernelMemoryAddress(uint64_t virtualAddress)
{
    return virtualAddress + HIGHER_HALF_KERNEL_MEMORY_OFFSET;
}

inline bool IsHigherHalf(uint64_t physicalAddress)
{
    return physicalAddress >= HIGHER_HALF_MEMORY_OFFSET;
}

inline bool IsKernelHigherHalf(uint64_t physicalAddress)
{
    return physicalAddress >= HIGHER_HALF_KERNEL_MEMORY_OFFSET;
}

#endif