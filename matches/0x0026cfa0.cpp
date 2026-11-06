#include "decls/data/engine/core.h"
// data: gState_26cfa0 = DAT_004cdbb0

#include "compat/ptr.h"
#include "gen/core.h"
extern "C" void* FUN_00266e00(int, hulk_intptr);
// the dl allocator's constructor 0x0026ce90 (returns the object)
struct MemoryDlAllocator_nv_26cfa0 {
    void* FUN_0026ce90(unsigned char, void*, int, const char*);
};
extern "C" void* FUN_0026cfa0(void* base, int size, int id, const char* name) {
    DAT_004cdbb0 = id;
    void* p = FUN_00266e00(id, sizeof(core::MemoryDlAllocator));
    if (p)
        return ((MemoryDlAllocator_nv_26cfa0*)p)->FUN_0026ce90(0, base, size, name);
    return 0;
}
