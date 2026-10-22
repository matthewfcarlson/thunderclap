// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13bd90;
extern int TypeA_13bd90;
extern int TypeB_13bd90;
struct AnimationAction_13bd90 {
    u32_13bd90 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationAction* Alloc(int);

int hulkfight::motion::AnimationTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_13bd90 a = (u32_13bd90)__p0; u32_13bd90 b = (u32_13bd90)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13bd90, &TypeB_13bd90, 0)) {
        hulkfight::motion::AnimationAction* q = Alloc(0x28);
        if (q)
            return (int)(((AnimationAction_13bd90*)(q))->Init(this, p));
    }
    return (int)(0);
}
