// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 14/14)
// FUN_0026b970 @ 0x0026b970
// equiv-conv: FUN_0026b910 eax
typedef unsigned int U_26b970;
struct Node { U_26b970 previousSize; U_26b970 size; Node* next; Node* previous; };
struct Heap_26b970 {
 U_26b970 flags;
 Node* fastBins[10];
 Node* top;
 U_26b970 reserved;
 U_26b970 binStorage[256];
 U_26b970 binmap[4];
 U_26b970 trimThreshold;
 U_26b970 topPad;
 U_26b970 mmapThreshold;
 U_26b970 mmapCount;
 U_26b970 mmapLimit;
 U_26b970 maxMmapCount;
 U_26b970 pageSize;
};
void FUN_0026b910(Heap_26b970* heap);
void __cdecl FUN_0026b970(Heap_26b970* heap) {
 U_26b970 count = heap->flags;
 if (!count) {
  FUN_0026b910(heap); // malloc_init_state: heap arrives in eax
  return;
 }
 heap->flags = count | 1;
 Node** end = (Node**)heap + ((count | 1) >> 3) - 1;
 for (Node** slot = heap->fastBins; ; ++slot) {
  Node* block = *slot;
  if (block) {
   *slot = 0;
   do {
    U_26b970 size = block->size;
    Node* next = block->next;
    U_26b970 actual = size & ~1u;
    Node* following = (Node*)((char*)block + actual);
    U_26b970 followingSize = following->size & ~3u;
    if (!(size & 1)) {
     U_26b970 previousSize = block->previousSize;
     actual += previousSize;
     block = (Node*)((char*)block - previousSize);
     Node* back = block->previous;
     Node* forward = block->next;
     forward->previous = back;
     back->next = forward;
    }
    if (following != heap->top) {
     U_26b970 used = ((Node*)((char*)following + followingSize))->size & 1;
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