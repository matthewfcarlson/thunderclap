// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_3 @ 0x0026cd90
#include "decls/data/engine/core.h"

namespace core {
struct MemoryDlAllocator {
    char pad0[12];
    unsigned int valueC;
    unsigned int value10;
    unsigned int value14;
    unsigned int value18;
    unsigned int value1c;
    char pad20[0x490-0x20];
    unsigned int allocationCount;
    unsigned int allocatedBytes;
    unsigned int peakBytes;
    void* vfunc_3(unsigned int size);
};
}
void* __cdecl FUN_0026c040(unsigned int size);
void* core::MemoryDlAllocator::vfunc_3(unsigned int size) {
    DAT_005283a0 = valueC;
    (*(void**)&DAT_0052839c) = &value1c;
    DAT_005283a8 = value10;
    (*(void**)&DAT_005283ac) = &value18;
    DAT_005283a4 = value14;
    void* result = FUN_0026c040(size);
    if (result) {
        unsigned int bytes = *(unsigned int*)((char*)result - 4) & ~3u;
        allocatedBytes += bytes;
        if (allocatedBytes > peakBytes) peakBytes = allocatedBytes;
        ++allocationCount;
    }
    return result;
}