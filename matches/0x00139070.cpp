// Same code shape as 0x00119fb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_139070;
extern int TypeA_139070, TypeB;
struct Params_139070 {
    int Init(hulkfight::motion::AirToGroundTargetTrack*, void*);
};
extern int IsKindOf(void*, int, int*, int*, int);
extern void* Alloc(hulk_uintptr);

hulk_intptr hulkfight::motion::AirToGroundTargetTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_139070 a = (u32_139070)__p0; u32_139070 b = (u32_139070)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_139070, &TypeB, 0)) {
        Params_139070* q = (Params_139070*)Alloc(0x34);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}
