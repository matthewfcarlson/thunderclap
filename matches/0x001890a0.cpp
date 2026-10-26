// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_1890a0;
extern int TypeA_1890a0;
extern int TypeB_1890a0;
struct Result_1890a0 {
    u32_1890a0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_1890a0* Alloc(int);

hulk_intptr hulkfight::motion::BallAndChainSpinTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1890a0 a = (u32_1890a0)__p0; u32_1890a0 b = (u32_1890a0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1890a0, &TypeB_1890a0, 0)) {
        Result_1890a0* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
