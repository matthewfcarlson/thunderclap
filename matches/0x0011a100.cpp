// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_11a100;
extern int TypeA_11a100;
extern int TypeB_11a100;
struct MotionFleeAction_nv_11a100 {
    u32_11a100 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::MotionFleeAction* Alloc(int);

hulk_intptr hulkfight::ai::MotionFleeTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_11a100 a = (u32_11a100)__p0; u32_11a100 b = (u32_11a100)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_11a100, &TypeB_11a100, 0)) {
        hulkfight::ai::MotionFleeAction* q = Alloc(0x28);
        if (q)
            return (int)(((MotionFleeAction_nv_11a100*)(((hulkfight::ai::MotionFleeAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
