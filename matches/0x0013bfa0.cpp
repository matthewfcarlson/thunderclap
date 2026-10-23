// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13bfa0;
extern int TypeA_13bfa0;
extern int TypeB_13bfa0;
struct AnimationChargeAction_nv_13bfa0 {
    u32_13bfa0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationChargeAction* Alloc(int);

int hulkfight::motion::AnimationChargeTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_13bfa0 a = (u32_13bfa0)__p0; u32_13bfa0 b = (u32_13bfa0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13bfa0, &TypeB_13bfa0, 0)) {
        hulkfight::motion::AnimationChargeAction* q = Alloc(0x28);
        if (q)
            return (int)(((AnimationChargeAction_nv_13bfa0*)(((hulkfight::motion::AnimationChargeAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
