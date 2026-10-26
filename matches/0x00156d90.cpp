// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_156d90;
extern int TypeA_156d90;
extern int TypeB_156d90;
struct HitWaitAction_nv_156d90 {
    u32_156d90 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::HitWaitAction* Alloc(int);

hulk_intptr hulkfight::motion::HitWaitTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_156d90 a = (u32_156d90)__p0; u32_156d90 b = (u32_156d90)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_156d90, &TypeB_156d90, 0)) {
        hulkfight::motion::HitWaitAction* q = Alloc(0x28);
        if (q)
            return (int)(((HitWaitAction_nv_156d90*)(((hulkfight::motion::HitWaitAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
