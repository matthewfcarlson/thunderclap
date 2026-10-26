// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_119f00;
extern int TypeA_119f00;
extern int TypeB_119f00;
struct MotionChaseAction_nv_119f00 {
    u32_119f00 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::MotionChaseAction* Alloc(int);

hulk_intptr hulkfight::ai::MotionChaseTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_119f00 a = (u32_119f00)__p0; u32_119f00 b = (u32_119f00)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_119f00, &TypeB_119f00, 0)) {
        hulkfight::ai::MotionChaseAction* q = Alloc(0x28);
        if (q)
            return (int)(((MotionChaseAction_nv_119f00*)(((hulkfight::ai::MotionChaseAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
