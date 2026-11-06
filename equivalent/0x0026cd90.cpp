// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_3 @ 0x0026cd90
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

namespace core {
struct MemoryDlAllocator {
    void* vtable;                   // +0x00 core::IMemoryAllocator
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    unsigned int size;              // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    unsigned int count;             // +0x490 allocations
    unsigned int total;             // +0x494 bytes in use
    unsigned int peak;              // +0x498
    void* vfunc_3(unsigned int size);
};
}
void* __cdecl FUN_0026c040(unsigned int size);
void* core::MemoryDlAllocator::vfunc_3(unsigned int bytes) {
    DAT_005283a0 = start;
    (*(DlHeapState**)&DAT_0052839c) = &heap;
    DAT_005283a8 = end;
    (*(hulk_intptr**)&DAT_005283ac) = &brk;
    DAT_005283a4 = size;
    void* result = FUN_0026c040(bytes);
    if (result) {
        unsigned int used = (unsigned int)(((hulk_uintptr*)result)[-1] & ~(hulk_uintptr)3);
        total += used;
        if (total > peak) peak = total;
        ++count;
    }
    return result;
}
