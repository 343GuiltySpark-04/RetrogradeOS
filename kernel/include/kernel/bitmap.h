#pragma once
#ifndef BITMAP_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct
{

    size_t size;
    uint8_t *buffer;

    /* data */

} bitmap_t;

inline bool bitmap_get(bitmap_t *bitmap, uint32_t index)
{
    if (index > bitmap->size * 4)
    {
        return false;
    }

    uint32_t byteIndex = index / 4;
    uint8_t bitIndex = index % 4;
    uint8_t bitIndexer = 0b1000 >> bitIndex;

    return ((bitmap->buffer[byteIndex] & bitIndexer) > 0);
}

#endif