#include "decls/data/engine/core.h"

#include "compat/ptr.h"
#include "gen/core.h"
extern "C" void* FUN_00266e00(int, hulk_intptr);
// the dl allocator's constructor 0x0026ca80 (an arena of `bytes` from heap `id`; returns the object)
struct MemoryDlAllocator_nv_26cf20 {
    void* FUN_0026ca80(int, int, const char*);
};
extern "C" void* __cdecl FUN_0026cf20(int bytes, int id, const char* name) {
    DAT_004cdbb0 = id;
    void* x = FUN_00266e00(id, sizeof(core::MemoryDlAllocator));
    if (x)
        return ((MemoryDlAllocator_nv_26cf20*)x)->FUN_0026ca80(bytes, id, name);
    return 0;
}
