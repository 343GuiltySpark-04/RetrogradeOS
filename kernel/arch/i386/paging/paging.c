/* sourcce code from https://github.com/LittleCodingFox/ToastOS/blob/master/src/low-level/paging/Paging.cpp
with some modifactions fo x86 */

#include <kernel/paging/paging.h>

PageTableOffset VirtualAddressToOffsets(void *virtualAddress)
{
    uint64_t address = (uint64_t)virtualAddress;

    PageTableOffset offset = {

        .p4Offset = (address & ((uint64_t)0x1FF << 39)) >> 39,
        .pdpOffset = (address & ((uint64_t)0x1FF << 30)) >> 30,
        .pdOffset = (address & ((uint64_t)0x1FF << 21)) >> 21,
        .ptOffset = (address & ((uint64_t)0x1FF << 12)) >> 12,
    };

    return offset;
}

void *OffsetToVirtualAddress(PageTableOffset offset)
{
    uint64_t address = 0;

    address |= offset.p4Offset << 39;
    address |= offset.pdpOffset << 30;
    address |= offset.pdOffset << 21;
    address |= offset.ptOffset << 12;

    return (void *)address;
}