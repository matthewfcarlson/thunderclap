#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"

extern "C" char DAT_0042af2c[];   // a vftable (slot 0)
extern "C" void __cdecl FUN_00270510(void);
extern "C" int* FUN_002705f0();
extern "C" void FUN_00270370();
extern "C" void FUN_00267280() {
    (*(unsigned char*)&DAT_00527f5c) = 1;
    FUN_00270510();
    (*(void**)&DAT_00527f50) = DAT_0042af2c;
    FUN_002705f0();
    (*(void**)&DAT_00527f58) = ((void**)&DAT_00527f50);
    DAT_00527f40.allocator = (void*)&DAT_00527f50;
    DAT_00527f40.child = 0;
    DAT_00527f40.next = 0;
    DAT_00527f40.parent = 0;
    unsigned i = 0;
    do {
        MemoryHeapSlot* e = (MemoryHeapSlot*)((char*)DAT_00527c60 + i);
        e->child = 0;
        e->parent = 0;
        e->next = 0;
        e->allocator = (void*)&DAT_00527f50;
        i += sizeof(MemoryHeapSlot);
    } while (i < 46 * sizeof(MemoryHeapSlot));
    FUN_00270370();
}
