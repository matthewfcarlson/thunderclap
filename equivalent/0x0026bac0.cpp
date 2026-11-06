// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 14/14)
// FUN_0026bac0 @ 0x0026bac0
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

struct HeapStats {
    int f464;
    int chunks;
    int bucketCount;
    int f450;
    int f460;
    int f470;
    int bucketBytes;
    int freeBytes;
    int totalBytes;
    unsigned int firstSize;
};

extern "C" void __cdecl FUN_0026b970(void *);

HeapStats FUN_0026bac0()
{
    DlHeapState *heap = (*(DlHeapState**)&DAT_0052839c);
    if (!heap->top)
        FUN_0026b970((DlHeapState *)heap);
    unsigned int firstSize = (unsigned int)(heap->top->size & ~(hulk_uintptr)3);

    int bucketCount = 0;
    int bucketBytes = 0;
    for (int i = 0; i < 10; i++) {
        for (DlHeapChunk *b = heap->fastBins[i]; b; b = b->next) {
            bucketCount++;
            bucketBytes += (int)(b->size & ~(hulk_uintptr)3);
        }
    }
    int total = firstSize + bucketBytes;
    int chunks = 1;
    for (int i = 0; i < 0x7f; i++) {
        DlHeapChunk *bin = (DlHeapChunk *)((char *)&heap->bins[2 * i + 2] - DlHeapChunk::kHeader);
        for (DlHeapChunk *c = bin->previous; c != bin; c = c->previous) {
            chunks++;
            total += (int)(c->size & ~(hulk_uintptr)3);
        }
    }
    HeapStats stats;
    stats.f464 = (int)heap->systemBytes;
    stats.freeBytes = stats.f464 - total;
    stats.f450 = (int)heap->mmapCount;
    stats.totalBytes = total;
    stats.f460 = (int)heap->mmappedBytes;
    stats.f470 = (int)heap->totalPeak;
    stats.bucketBytes = bucketBytes;
    stats.bucketCount = bucketCount;
    stats.chunks = chunks;
    stats.firstSize = firstSize;
    return stats;
}
