// STATUS: equivalent (tools/equiv.py level 3: 2747 inputs, branch coverage 16/16)
// FUN_0026bd80 @ 0x0026bd80
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

extern "C" void __cdecl FUN_0026b970(void *);
extern "C" void __cdecl FUN_0026bd80(void* memory) {
    if (!memory) return;
    DlHeapChunk* block = (DlHeapChunk*)((char*)memory - DlHeapChunk::kHeader);
    hulk_uintptr originalSize = block->size;
    hulk_uintptr size = originalSize & ~(hulk_uintptr)3;
    DlHeapState* heap = (*(DlHeapState**)&DAT_0052839c);
    if (size <= heap->maxFast) {
        heap->maxFast &= ~(hulk_uintptr)1;
        DlHeapChunk** slot = &heap->fastBins[(size >> 3) - 2];
        block->next = *slot;
        *slot = block;
        return;
    }
    if (originalSize & 2) return;
    DlHeapChunk* next = (DlHeapChunk*)((char*)block + size);
    hulk_uintptr nextSize = next->size & ~(hulk_uintptr)3;
    if (!(originalSize & 1)) {
        size += block->previousSize;
        block = (DlHeapChunk*)((char*)block - block->previousSize);
        block->next->previous = block->previous;
        block->previous->next = block->next;
    }
    if (next == heap->top) {
        size += nextSize;
        block->size = size | 1;
        heap->top = block;
    } else {
        hulk_uintptr followingFlag = ((DlHeapChunk*)((char*)next + nextSize))->size & 1;
        next->size = nextSize;
        if (!followingFlag) {
            next->next->previous = next->previous;
            next->previous->next = next->next;
            size += nextSize;
        }
        DlHeapChunk* sentinel = (DlHeapChunk*)((char*)&heap->bins[2] - DlHeapChunk::kHeader);
        DlHeapChunk* first = sentinel->next;
        block->previous = sentinel;
        block->next = first;
        sentinel->next = block;
        first->previous = block;
        block->size = size | 1;
        ((DlHeapChunk*)((char*)block + size))->previousSize = size;
    }
    if (size >= 0x10000 && !(heap->maxFast & 1)) FUN_0026b970((DlHeapState *)heap);
}
