// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 16/16)
// FUN_0026bd80 @ 0x0026bd80
struct Block_26bd80 { unsigned previousSize; unsigned size; Block_26bd80* next; Block_26bd80* previous; };
struct Heap_26bd80 { unsigned limit; unsigned smallBins[10]; Block_26bd80* top; unsigned unused; Block_26bd80 sentinel; };
extern Heap_26bd80* DAT_0052839c;
void __cdecl FUN_0026b970(Heap_26bd80* heap);
void __cdecl FUN_0026bd80(void* memory) {
    if (!memory) return;
    Block_26bd80* block = (Block_26bd80*)((char*)memory - 8);
    unsigned originalSize = block->size;
    unsigned size = originalSize & ~3u;
    Heap_26bd80* heap = DAT_0052839c;
    if (size <= heap->limit) {
        heap->limit &= ~1u;
        Block_26bd80** slot = ((Block_26bd80**)heap) + (size >> 3) - 1;
        block->next = *slot;
        *slot = block;
        return;
    }
    if (originalSize & 2) return;
    Block_26bd80* next = (Block_26bd80*)((char*)block + size);
    unsigned nextSize = next->size & ~3u;
    if (!(originalSize & 1)) {
        size += block->previousSize;
        block = (Block_26bd80*)((char*)block - block->previousSize);
        block->next->previous = block->previous;
        block->previous->next = block->next;
    }
    if (next == heap->top) {
        size += nextSize;
        block->size = size | 1;
        heap->top = block;
    } else {
        unsigned followingFlag = ((Block_26bd80*)((char*)next + nextSize))->size & 1;
        next->size = nextSize;
        if (!followingFlag) {
            next->next->previous = next->previous;
            next->previous->next = next->next;
            size += nextSize;
        }
        Block_26bd80* first = heap->sentinel.next;
        block->previous = &heap->sentinel;
        block->next = first;
        heap->sentinel.next = block;
        first->previous = block;
        block->size = size | 1;
        ((Block_26bd80*)((char*)block + size))->previousSize = size;
    }
    if (size >= 0x10000 && !(heap->limit & 1)) FUN_0026b970(heap);
}