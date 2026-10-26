#include "decls/data/engine/core.h"

#include "compat/ptr.h"
#include "gen/core.h"
typedef unsigned int U_26cf20;
extern U_26cf20 __cdecl lookup(U_26cf20, U_26cf20);
struct MemoryDlAllocator_nv_26cf20 {
    U_26cf20 run(hulk_uintptr, U_26cf20, U_26cf20);
};
hulk_uintptr __cdecl target(hulk_uintptr a, U_26cf20 b, U_26cf20 c) {
    (*(U_26cf20*)&DAT_004cdbb0) = b;
    hulk_uintptr x = lookup(b, 0x4a4);
    if (x)
        return ((MemoryDlAllocator_nv_26cf20*)(((core::MemoryDlAllocator*)(((core::MemoryDlAllocator*)x)))))->run(a, b, c);
    return 0;
}