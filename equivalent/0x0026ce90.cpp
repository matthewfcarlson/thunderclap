// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0026ce90 @ 0x0026ce90
// The dl allocator's constructor on memory the caller gives it (0x0026cfa0, 0x0026cf60): the arena is [base,
// base + size). Written as a member named by its address with the vftable stores spelled out, so that the 64-bit
// builds bind the callers' references by address and the object gets the game's vftables (include/gen/core.h's
// core::MemoryDlAllocator has the same layout).
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

// the vftables (slot 0 labels): core::IMemoryAllocator, core::Object, then core::MemoryDlAllocator's two
extern "C" char DAT_0042aef4[];
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b36c[];
extern "C" char DAT_0042b364[];
extern "C" int* FUN_002705f0();
struct MemoryDlAllocator_26ce90 {
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
    MemoryDlAllocator_26ce90* FUN_0026ce90(unsigned char inPlace, void* base, int size, const char* name);
};
MemoryDlAllocator_26ce90* MemoryDlAllocator_26ce90::FUN_0026ce90(unsigned char mode, void* base, int bytes, const char*) {
    vtable = DAT_0042aef4;
    vtableObject = DAT_0042afa8;
    heapId = DAT_004cdbb0;
    FUN_002705f0();
    vtable = DAT_0042b36c;
    vtableObject = DAT_0042b364;
    count = total = peak = 0;
    ownsArena = 0;
    inPlace = mode;
    refs = 0;
    FUN_002705f0();
    start = (hulk_intptr)base;
    end = (hulk_intptr)base + bytes;
    size = bytes;
    brk = (hulk_intptr)base;
    for (unsigned int i = 0; i < sizeof(DlHeapState) / sizeof(hulk_uintptr); ++i)
        ((hulk_uintptr*)&heap)[i] = 0;
    return this;
}
