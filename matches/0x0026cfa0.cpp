#include "gen/core.h"
extern int gState_26cfa0;
int Check(int, int);
struct MemoryDlAllocator_nv_26cfa0 {
    int Do(int, int, int, int);
};
int Target(int a, int b, int c, int d) {
    gState_26cfa0 = c;
    core::MemoryDlAllocator* p = (core::MemoryDlAllocator*)Check(c, 0x4a4);
    if (p)
        return ((MemoryDlAllocator_nv_26cfa0*)(p))->Do(0, a, b, d);
    return 0;
}