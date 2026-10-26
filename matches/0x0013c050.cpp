// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_13c050;
extern int TypeA_13c050;
extern int TypeB_13c050;
struct AnimationLinkedAction_nv_13c050 {
    u32_13c050 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationLinkedAction* Alloc(int);

hulk_intptr hulkfight::motion::AnimationLinkedTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_13c050 a = (u32_13c050)__p0; u32_13c050 b = (u32_13c050)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13c050, &TypeB_13c050, 0)) {
        hulkfight::motion::AnimationLinkedAction* q = Alloc(0x28);
        if (q)
            return (int)(((AnimationLinkedAction_nv_13c050*)(((hulkfight::motion::AnimationLinkedAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
