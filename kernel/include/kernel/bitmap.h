
/* source code from https://github.com/LittleCodingFox/ToastOS/blob/master/src/low-level/Bitmap.hpp
with some modifactions fo x86 and ported to C */

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

inline bool bitmap_set(bitmap_t *bitmap, uint32_t index, bool value)
{
    if (index > bitmap->size * 8)
    {
        return false;
    }

    uint32_t byteIndex = index / 8;
    uint8_t bitIndex = index % 8;
    uint8_t bitIndexer = 0b10000000 >> bitIndex;

    bitmap->buffer[byteIndex] &= ~bitIndexer;

    if (value)
    {
        bitmap->buffer[byteIndex] |= bitIndexer;
    }

    return true;
}

inline uint8_t GetBit(bitmap_t *bitmap, size_t bit)
{
    size_t bitmapIndex = bit / 4;
    size_t bitIndex = bit % 4;

    return bitmap->buffer[bitmapIndex] & (1 << bitIndex);
}

inline void SetBit(bitmap_t *bitmap, size_t bit, uint8_t value)
{
    size_t bitmapIndex = bit / 4;
    size_t bitIndex = bit % 4;

    if (value)
    {
        bitmap->buffer[bitmapIndex] |= (1 << bitIndex);
    }
    else
    {
        bitmap->buffer[bitmapIndex] &= ~(1 << bitIndex);
    }

#endif