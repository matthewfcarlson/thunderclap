// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13be40;
extern int TypeA_13be40;
extern int TypeB_13be40;
struct AnimationPhaseMatchedAction_13be40 {
    u32_13be40 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationPhaseMatchedAction* Alloc(int);

int hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_13be40 a = (u32_13be40)__p0; u32_13be40 b = (u32_13be40)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13be40, &TypeB_13be40, 0)) {
        hulkfight::motion::AnimationPhaseMatchedAction* q = Alloc(0x28);
        if (q)
            return (int)(((AnimationPhaseMatchedAction_13be40*)(q))->Init(this, p));
    }
    return (int)(0);
}
