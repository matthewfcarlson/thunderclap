// STATUS: equivalent (tools/equiv.py level 3: 22 inputs, branch coverage 16/16)
// FUN_0026b970 @ 0x0026b970
typedef unsigned int U;
struct Node { U previousSize; U size; Node* next; Node* previous; };
struct Heap {
 U flags;
 Node* fastBins[10];
 Node* top;
 U reserved;
 U binStorage[256];
 U binmap[4];
 U trimThreshold;
 U topPad;
 U mmapThreshold;
 U mmapCount;
 U mmapLimit;
 U maxMmapCount;
 U pageSize;
};
void __cdecl FUN_0026b970(Heap* heap) {
 U count = heap->flags;
 if (!count) {
  for (U i = 0; i < 127; ++i) {
   Node* bin = (Node*)&heap->binStorage[i * 2];
   bin->next = bin;
   bin->previous = bin;
  }
  heap->top = (Node*)heap->binStorage;
  heap->flags = 9;
  heap->trimThreshold = 0x20000;
  heap->topPad = 0;
  heap->mmapThreshold = 0x20000;
  heap->mmapLimit = 0;
  heap->pageSize = 4096;
  return;
 }
 heap->flags = count | 1;
 Node** end = (Node**)heap + ((count | 1) >> 3) - 1;
 for (Node** slot = heap->fastBins; ; ++slot) {
  Node* block = *slot;
  if (block) {
   *slot = 0;
   do {
    U size = block->size;
    Node* next = block->next;
    U actual = size & ~1u;
    Node* following = (Node*)((char*)block + actual);
    U followingSize = following->size & ~3u;
    if (!(size & 1)) {
     U previousSize = block->previousSize;
     actual += previousSize;
     block = (Node*)((char*)block - previousSize);
     Node* back = block->previous;
     Node* forward = block->next;
     forward->previous = back;
     back->next = forward;
    }
    if (following != heap->top) {
     U used = ((Node*)((char*)following + followingSize))->size & 1;
     following->size = followingSize;
     if (!used) {
      actual += followingSize;
      Node* forward = following->next;
      Node* back = following->previous;
      forward->previous = back;
      back->next = forward;
     }
     Node* sentinel = (Node*)heap->binStorage;
     Node* old = sentinel->next;
     sentinel->next = block;
     old->previous = block;
     block->size = actual | 1;
     block->previous = sentinel;
     block->next = old;
     ((Node*)((char*)block + actual))->previousSize = actual;
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