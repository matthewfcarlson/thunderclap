// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 7/8, incomplete)
// FUN_00267110 @ 0x00267110
#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"

struct Object { virtual void unused(); virtual void FUN_00000000(); };
extern "C" void __cdecl FUN_00267110(unsigned int index) {
    MemoryHeapSlot* entry = &DAT_00527c60[index];
    MemoryHeapSlot* list = entry->parent;
    MemoryHeapSlot* current = list->child;
    MemoryHeapSlot* previous = 0;
    if (!current) return;
    while (current != entry) {
        previous = current;
        current = current->next;
        if (!current) return;
    }
    if (previous) previous->next = entry->next;
    else list->child = entry->next;
    ((Object*)entry->allocator)->FUN_00000000();
    entry->allocator = (*(void**)&DAT_00527f58);
    entry->child = 0;
    entry->parent = 0;
    entry->next = 0;
}
