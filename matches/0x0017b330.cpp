// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_17b330;
extern int TypeA_17b330;
extern int TypeB_17b330;
struct Result_17b330 {
    u32_17b330 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_17b330* Alloc(int);

hulk_intptr hulkfight::motion::ChargeTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b330 a = (u32_17b330)__p0; u32_17b330 b = (u32_17b330)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_17b330, &TypeB_17b330, 0)) {
        Result_17b330* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
