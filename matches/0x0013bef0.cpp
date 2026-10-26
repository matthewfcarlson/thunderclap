// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_13bef0;
extern int TypeA_13bef0;
extern int TypeB_13bef0;
struct AnimationVelocityScaledAction_nv_13bef0 {
    u32_13bef0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationVelocityScaledAction* Alloc(int);

hulk_intptr hulkfight::motion::AnimationVelocityScaledTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_13bef0 a = (u32_13bef0)__p0; u32_13bef0 b = (u32_13bef0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13bef0, &TypeB_13bef0, 0)) {
        hulkfight::motion::AnimationVelocityScaledAction* q = Alloc(0x28);
        if (q)
            return (int)(((AnimationVelocityScaledAction_nv_13bef0*)(((hulkfight::motion::AnimationVelocityScaledAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
