// STATUS: equivalent (tools/equiv.py level 3: 2575 inputs, branch coverage 25/26, incomplete)
// FUN_0026c6a0 @ 0x0026c6a0
#include "compat/ptr.h"
#include "decls/data/records.h"
typedef unsigned int uint32_26c6a0;
extern "C" void* __cdecl FUN_0026c040(uint32_26c6a0 size);
extern "C" void __cdecl FUN_0026bd80(void* ptr);

extern "C" void* __cdecl FUN_0026c6a0(unsigned int alignment, unsigned int size)
{
    if (alignment <= DlHeapChunk::kAlign)
        return FUN_0026c040(size);
    if (alignment < DlHeapChunk::kMinSize)
        alignment = DlHeapChunk::kMinSize;
    if (alignment & (alignment - 1)) {
        uint32_26c6a0 power = DlHeapChunk::kMinSize;
        while (power < alignment)
            power <<= 1;
        alignment = power;
    }
    if ((hulk_uintptr)size >= (hulk_uintptr)-(hulk_intptr)(2 * DlHeapChunk::kMinSize))
        return 0;
    hulk_uintptr rounded = (hulk_uintptr)size + DlHeapChunk::kWord + DlHeapChunk::kAlignMask;
    if (rounded < DlHeapChunk::kMinSize)
        rounded = DlHeapChunk::kMinSize;
    else
        rounded &= ~(hulk_uintptr)DlHeapChunk::kAlignMask;
    char* allocation = (char*)FUN_0026c040((uint32_26c6a0)(alignment + rounded + DlHeapChunk::kMinSize));
    if (!allocation)
        return 0;
    DlHeapChunk* initial = (DlHeapChunk*)(allocation - DlHeapChunk::kHeader);
    DlHeapChunk* chunk = initial;
    if (((hulk_uintptr)allocation % alignment) != 0) {
        chunk = (DlHeapChunk*)((((hulk_uintptr)allocation + alignment - 1) & ~(hulk_uintptr)(alignment - 1)) - DlHeapChunk::kHeader);
        if ((hulk_uintptr)((char*)chunk - (char*)initial) < DlHeapChunk::kMinSize)
            chunk = (DlHeapChunk*)((char*)chunk + alignment);
        hulk_uintptr distance = (hulk_uintptr)((char*)chunk - (char*)initial);
        hulk_uintptr remainder = (initial->size & ~(hulk_uintptr)3) - distance;
        if (initial->size & 2) {
            chunk->size = remainder | 2;
            chunk->previousSize = initial->previousSize + distance;
            return (char*)chunk + DlHeapChunk::kHeader;
        }
        chunk->size = remainder | 1;
        ((DlHeapChunk*)((char*)chunk + remainder))->size |= 1;
        initial->size = (initial->size & 1) | distance;
        FUN_0026bd80((char*)initial + DlHeapChunk::kHeader);
    }
    if (!(chunk->size & 2)) {
        hulk_uintptr chunkSize = chunk->size & ~(hulk_uintptr)3;
        if (chunkSize > rounded + DlHeapChunk::kMinSize) {
            ((DlHeapChunk*)((char*)chunk + rounded))->size = (chunkSize - rounded) | 1;
            chunk->size = (chunk->size & 1) | rounded;
            FUN_0026bd80((char*)chunk + rounded + DlHeapChunk::kHeader);
        }
    }
    return (char*)chunk + DlHeapChunk::kHeader;
}
