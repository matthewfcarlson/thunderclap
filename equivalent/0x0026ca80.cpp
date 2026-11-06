// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0026ca80 @ 0x0026ca80
// The dl allocator's constructor with an arena of `bytes` from heap `heapFrom` (0x0026cf20), which it owns. As
// 0x0026ce90: a member named by its address, the vftable stores spelled out.
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

// the vftables (slot 0 labels): core::IMemoryAllocator, core::Object, then core::MemoryDlAllocator's two
extern "C" char DAT_0042aef4[];
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b36c[];
extern "C" char DAT_0042b364[];
extern "C" int* FUN_002705f0();
extern "C" void* FUN_00266e00(int, hulk_intptr);
struct MemoryDlAllocator_26ca80 {
    void* vtable;                   // +0x00 core::IMemoryAllocator
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08 core::Object: the heap the allocator itself came from
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    int size;                       // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    int count;                      // +0x490 allocations
    int total;                      // +0x494 bytes in use
    int peak;                       // +0x498
    unsigned char ownsArena;        // +0x49c the arena came from heapId's allocator (0x0026cc40 frees it)
    unsigned char inPlace;          // +0x49d the allocator sits in memory it does not own (0x0026cc40 only destroys it)
    char pad[2];
    int refs;                       // +0x4a0
    MemoryDlAllocator_26ca80* FUN_0026ca80(int bytes, int heapFrom, const char* name);
};
MemoryDlAllocator_26ca80* MemoryDlAllocator_26ca80::FUN_0026ca80(int bytes, int heapFrom, const char*) {
    vtable = DAT_0042aef4;
    vtableObject = DAT_0042afa8;
    heapId = DAT_004cdbb0;
    FUN_002705f0();
    vtable = DAT_0042b36c;
    vtableObject = DAT_0042b364;
    count = total = peak = 0;
    ownsArena = 1;
    inPlace = 0;
    refs = 0;
    FUN_002705f0();
    size = bytes;
    hulk_intptr arena = (hulk_intptr)FUN_00266e00(heapFrom, bytes);
    start = arena;
    brk = arena;
    end = size + arena;
    for (unsigned int i = 0; i < sizeof(DlHeapState) / sizeof(hulk_uintptr); ++i)
        ((hulk_uintptr*)&heap)[i] = 0;
    return this;
}
