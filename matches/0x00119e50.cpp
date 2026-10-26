// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_119e50;
extern int TypeA_119e50;
extern int TypeB_119e50;
struct MotionTargetAction_nv_119e50 {
    u32_119e50 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::MotionTargetAction* Alloc(int);

hulk_intptr hulkfight::ai::MotionTargetTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_119e50 a = (u32_119e50)__p0; u32_119e50 b = (u32_119e50)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_119e50, &TypeB_119e50, 0)) {
        hulkfight::ai::MotionTargetAction* q = Alloc(0x28);
        if (q)
            return (int)(((MotionTargetAction_nv_119e50*)(((hulkfight::ai::MotionTargetAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
