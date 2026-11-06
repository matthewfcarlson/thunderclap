#include "compat/ptr.h"
#include "gen/core.h"
// 0x0026fd50 rounds a size up to an alignment (a class-scope declaration: the TU's C declaration of it is spelled
// with another source's typedef)
struct Align_26cf60 {
    static hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, unsigned int);
};
// the dl allocator's constructor 0x0026ce90 (returns the object)
struct MemoryDlAllocator_nv_26cf60 {
    void* FUN_0026ce90(unsigned char, void*, int, const char*);
};

// a dl allocator placed at the start of [base, base + total): its arena is the rest
void* __cdecl FUN_0026cf60(void* base, int total, const char* name) {
    int size = (int)Align_26cf60::FUN_0026fd50(sizeof(core::MemoryDlAllocator), 4);
    if (base != 0)
        return ((MemoryDlAllocator_nv_26cf60*)base)->FUN_0026ce90(1, (char*)base + size, total - size, name);
    return 0;
}
