#include "decls/data/engine/core.h"
// data: gState_26cfa0 = DAT_004cdbb0

#include "compat/ptr.h"
#include "gen/core.h"
hulk_intptr Check(int, int);
struct MemoryDlAllocator_nv_26cfa0 {
    int Do(int, int, int, int);
};
int Target(int a, int b, int c, int d) {
    DAT_004cdbb0 = c;
    core::MemoryDlAllocator* p = (core::MemoryDlAllocator*)Check(c, 0x4a4);
    if (p)
        return ((MemoryDlAllocator_nv_26cfa0*)(((core::MemoryDlAllocator*)(p))))->Do(0, a, b, d);
    return 0;
}