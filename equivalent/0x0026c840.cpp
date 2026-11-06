// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 32/32)
// FUN_0026c840 @ 0x0026c840
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

typedef unsigned int uint_26c840;
extern "C" void __cdecl FUN_0026b970(void *);
void * __cdecl FUN_0026c040(uint_26c840);
// a request's chunk size (the request plus the size word, aligned; at least the minimum chunk)
static inline hulk_uintptr chunk_size_26c840(hulk_uintptr request) {
    hulk_uintptr n = request + DlHeapChunk::kWord + DlHeapChunk::kAlignMask;
    return n < DlHeapChunk::kMinSize ? DlHeapChunk::kMinSize : n & ~(hulk_uintptr)DlHeapChunk::kAlignMask;
}
// equiv-conv: FUN_0026c840 eax stack stack stack
void ** __cdecl FUN_0026c840(void **result, uint_26c840 count, const uint_26c840 *sizes, uint_26c840 flags)
{
    DlHeapState *state = (*(DlHeapState**)&DAT_0052839c);
    if (!(state->maxFast & 1)) FUN_0026b970((DlHeapState *)state);
    if (!count) {
        if (result) return result;
        return (void **)FUN_0026c040(0);
    }
    hulk_uintptr arraySize = 0;
    if (!result)
        arraySize = chunk_size_26c840((hulk_uintptr)count * sizeof(void *));
    hulk_uintptr uniform = 0, total = 0;
    if (flags & 1) {
        uniform = chunk_size_26c840(sizes[0]);
        total = uniform * count;
    } else {
        for (uint_26c840 i = 0; i != count; ++i)
            total += chunk_size_26c840(sizes[i]);
    }
    hulk_uintptr saved = state->mmapMax;
    state->mmapMax = 0;
    char *memory = (char *)FUN_0026c040((uint_26c840)(arraySize + total - DlHeapChunk::kAlignMask));
    (*(DlHeapState**)&DAT_0052839c)->mmapMax = saved;
    if (!memory) return 0;
    DlHeapChunk *block = (DlHeapChunk *)(memory - DlHeapChunk::kHeader);
    hulk_uintptr remaining = block->size & ~(hulk_uintptr)3;
    if (flags & 2) {
        hulk_uintptr len = remaining - arraySize - DlHeapChunk::kWord;
        for (hulk_uintptr j = 0; j != len; ++j) memory[j] = 0;
    }
    if (!result) {
        DlHeapChunk *arrayChunk = (DlHeapChunk *)((char *)block + total);
        arrayChunk->size = (remaining - total) | 1;
        result = (void **)((char *)arrayChunk + DlHeapChunk::kHeader);
        remaining = total;
    }
    result[0] = (char *)block + DlHeapChunk::kHeader;
    for (uint_26c840 k = 1; k != count; ++k) {
        hulk_uintptr n = uniform;
        if (!n)
            n = chunk_size_26c840(sizes[k-1]);
        block->size = n | 1;
        block = (DlHeapChunk *)((char *)block + n);
        remaining -= n;
        result[k] = (char *)block + DlHeapChunk::kHeader;
    }
    block->size = remaining | 1;
    return result;
}
