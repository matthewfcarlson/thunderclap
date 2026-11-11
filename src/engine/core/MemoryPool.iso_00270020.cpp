// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026fd50..0x00270370 (kind game, layer engine, confidence high), dominant class core::MemoryPool
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00270020 FUN_00270020 (138 B): equivalent/0x00270020.cpp [isolated: code differs from its standalone build; on include/gen/ and not mergeable]
// sym: ?FUN_00270020@Pool_270020@owners@@QAEXPAXIII0II@Z @b12452c48024 @we4fc503ced1c
// STATUS: equivalent (tools/equiv.py level 3: 41 inputs, branch coverage 6/6)
// FUN_00270020 @ 0x00270020
#include "gen/owners.h"
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, unsigned);
extern "C" void* __cdecl FUN_00266eb0(void*, hulk_uintptr, unsigned);
void owners::Pool_270020::FUN_00270020(void* buffer, unsigned itemSize, unsigned itemCount, unsigned flagsValue, void* allocator, hulk_uintptr unused6, unsigned itemAdjustment) {
    stride = FUN_0026fd50(itemSize, itemAdjustment);
    count = itemCount;
    flags = flagsValue;
    zero28 = 0;
    zero2c = 0;
    owner = allocator;
    zero30 = 0;
    void* base;
    if (buffer == 0)
        base = FUN_00266eb0(allocator, stride * itemCount, 4);
    else
        base = (void*)FUN_0026fd50((hulk_uintptr)buffer, 4);
    blocks = base;
    freeHead = 0;
    char* ptr = (char*)base;
    for (unsigned i = 0; i < count; ++i) {
        *(void**)ptr = freeHead;
        freeHead = ptr;
        ptr += stride;
    }
}

