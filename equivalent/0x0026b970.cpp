// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 14/14)
// FUN_0026b970 @ 0x0026b970
#include "compat/ptr.h"
#include "decls/data/records.h"

// equiv-conv: FUN_0026b910 eax
extern "C" void __cdecl FUN_0026b910(void *);
extern "C" void __cdecl FUN_0026b970(void * heap_) {
 DlHeapState * heap = (DlHeapState *)heap_;
 hulk_uintptr count = heap->maxFast;
 if (!count) {
  FUN_0026b910(heap); // malloc_init_state: heap arrives in eax
  return;
 }
 heap->maxFast = count | 1;
 DlHeapChunk** end = &heap->fastBins[((count | 1) >> 3) - 2];
 for (DlHeapChunk** slot = heap->fastBins; ; ++slot) {
  DlHeapChunk* block = *slot;
  if (block) {
   *slot = 0;
   do {
    hulk_uintptr size = block->size;
    DlHeapChunk* next = block->next;
    hulk_uintptr actual = size & ~(hulk_uintptr)1;
    DlHeapChunk* following = (DlHeapChunk*)((char*)block + actual);
    hulk_uintptr followingSize = following->size & ~(hulk_uintptr)3;
    if (!(size & 1)) {
     hulk_uintptr previousSize = block->previousSize;
     actual += previousSize;
     block = (DlHeapChunk*)((char*)block - previousSize);
     DlHeapChunk* back = block->previous;
     DlHeapChunk* forward = block->next;
     forward->previous = back;
     back->next = forward;
    }
    if (following != heap->top) {
     hulk_uintptr used = ((DlHeapChunk*)((char*)following + followingSize))->size & 1;
     following->size = followingSize;
     if (!used) {
      actual += followingSize;
      DlHeapChunk* forward = following->next;
      DlHeapChunk* back = following->previous;
      forward->previous = back;
      back->next = forward;
     }
     DlHeapChunk* sentinel = (DlHeapChunk*)((char*)&heap->bins[2] - DlHeapChunk::kHeader);
     DlHeapChunk* old = sentinel->next;
     sentinel->next = block;
     old->previous = block;
     block->size = actual | 1;
     block->previous = sentinel;
     block->next = old;
     ((DlHeapChunk*)((char*)block + actual))->previousSize = actual;
    } else {
     block->size = (followingSize + actual) | 1;
     heap->top = block;
    }
    block = next;
   } while (block);
  }
  if (slot == end) break;
 }
}
