// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 25/26, incomplete)
// FUN_0026c6a0 @ 0x0026c6a0
typedef unsigned int uint32_26c6a0;
extern "C" void* __cdecl FUN_0026c040(uint32_26c6a0 size);
extern "C" void __cdecl FUN_0026bd80(void* ptr);
struct ChunkHeader { uint32_26c6a0 previousSize; uint32_26c6a0 sizeFlags; };

void* __cdecl FUN_0026c6a0(uint32_26c6a0 alignment, uint32_26c6a0 size)
{
    if (alignment <= 8)
        return FUN_0026c040(size);
    if (alignment < 16)
        alignment = 16;
    if (alignment & (alignment - 1)) {
        uint32_26c6a0 power = 16;
        while (power < alignment)
            power <<= 1;
        alignment = power;
    }
    if (size >= 0xffffffe0U)
        return 0;
    uint32_26c6a0 rounded = size + 11;
    if (rounded < 16)
        rounded = 16;
    else
        rounded &= ~7U;
    char* allocation = (char*)FUN_0026c040(alignment + rounded + 16);
    if (!allocation)
        return 0;
    ChunkHeader* initial = (ChunkHeader*)(allocation - 8);
    ChunkHeader* chunk = initial;
    if (((uint32_26c6a0)allocation % alignment) != 0) {
        chunk = (ChunkHeader*)((((uint32_26c6a0)allocation + alignment - 1) & ~(alignment - 1)) - 8);
        if ((uint32_26c6a0)((char*)chunk - (char*)initial) < 16)
            chunk = (ChunkHeader*)((char*)chunk + alignment);
        uint32_26c6a0 distance = (uint32_26c6a0)((char*)chunk - (char*)initial);
        uint32_26c6a0 remainder = (initial->sizeFlags & ~3U) - distance;
        if (initial->sizeFlags & 2) {
            chunk->sizeFlags = remainder | 2;
            chunk->previousSize = initial->previousSize + distance;
            return (char*)chunk + 8;
        }
        chunk->sizeFlags = remainder | 1;
        *(uint32_26c6a0*)((char*)chunk + remainder + 4) |= 1;
        initial->sizeFlags = (initial->sizeFlags & 1) | distance;
        FUN_0026bd80((char*)initial + 8);
    }
    if (!(chunk->sizeFlags & 2)) {
        uint32_26c6a0 chunkSize = chunk->sizeFlags & ~3U;
        if (chunkSize > rounded + 16) {
            *(uint32_26c6a0*)((char*)chunk + rounded + 4) = (chunkSize - rounded) | 1;
            chunk->sizeFlags = (chunk->sizeFlags & 1) | rounded;
            FUN_0026bd80((char*)chunk + rounded + 8);
        }
    }
    return (char*)chunk + 8;
}