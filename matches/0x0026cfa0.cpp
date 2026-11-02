#include "decls/data/engine/core.h"
// data: gState_26cfa0 = DAT_004cdbb0

#include "compat/ptr.h"
#include "gen/core.h"
extern "C" hulk_intptr FUN_00266e00(int, int);
struct MemoryDlAllocator_nv_26cfa0 {
    int Do(int, int, int, int);
};
extern "C" int FUN_0026cfa0(int a, int b, int c, int d) {
    DAT_004cdbb0 = c;
    core::MemoryDlAllocator* p = (core::MemoryDlAllocator*)FUN_00266e00(c, 0x4a4);
    if (p)
        return ((MemoryDlAllocator_nv_26cfa0*)(((core::MemoryDlAllocator*)(p))))->Do(0, a, b, d);
    return 0;
}