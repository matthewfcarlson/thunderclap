// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 31/32, incomplete)
// FUN_0026c840 @ 0x0026c840
#include "decls/data/engine/core.h"

typedef unsigned int uint_26c840;
struct AllocState { unsigned char flags; char pad[0x453]; uint_26c840 saved; };
struct Chunk { uint_26c840 previousSize; uint_26c840 size; };
void __cdecl FUN_0026b970(AllocState *);
void * __cdecl FUN_0026c040(uint_26c840);
// equiv-conv: FUN_0026c840 eax stack stack stack
void ** __cdecl FUN_0026c840(void **result, uint_26c840 count, const uint_26c840 *sizes, uint_26c840 flags)
{
    AllocState *state = (*(AllocState**)&DAT_0052839c);
    if (!(state->flags & 1)) FUN_0026b970(state);
    if (!count) {
        if (result) return result;
        return (void **)FUN_0026c040(0);
    }
    uint_26c840 arraySize = 0;
    if (!result) {
        uint_26c840 n = count * 4 + 11;
        arraySize = n < 16 ? 16 : n & ~7u;
    }
    uint_26c840 uniform = 0, total = 0;
    if (flags & 1) {
        uint_26c840 n = sizes[0] + 11;
        uniform = n < 16 ? 16 : n & ~7u;
        total = uniform * count;
    } else {
        for (uint_26c840 i = 0; i != count; ++i) {
            uint_26c840 n = sizes[i] + 11;
            total += n < 16 ? 16 : n & ~7u;
        }
    }
    uint_26c840 saved = state->saved;
    state->saved = 0;
    char *memory = (char *)FUN_0026c040(arraySize + total - 7);
    (*(AllocState**)&DAT_0052839c)->saved = saved;
    if (!memory) return 0;
    Chunk *block = (Chunk *)memory - 1;
    uint_26c840 remaining = block->size & ~3u;
    if (flags & 2) {
        uint_26c840 len = remaining - arraySize - 4;
        for (uint_26c840 j = 0; j != len; ++j) memory[j] = 0;
    }
    if (!result) {
        Chunk *arrayChunk = (Chunk *)((char *)block + total);
        arrayChunk->size = (remaining - total) | 1;
        result = (void **)(arrayChunk + 1);
        remaining = total;
    }
    result[0] = block + 1;
    for (uint_26c840 k = 1; k != count; ++k) {
        uint_26c840 n = uniform;
        if (!n) {
            n = sizes[k-1] + 11;
            n = n < 16 ? 16 : n & ~7u;
        }
        block->size = n | 1;
        block = (Chunk *)((char *)block + n);
        remaining -= n;
        result[k] = block + 1;
    }
    block->size = remaining | 1;
    return result;
}