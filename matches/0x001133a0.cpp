// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_1133a0;
extern int TypeA_1133a0;
extern int TypeB_1133a0;
struct SemaphoreWaitAction_nv_1133a0 {
    u32_1133a0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::SemaphoreWaitAction* Alloc(int);

int hulkfight::ai::SemaphoreWaitTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_1133a0 a = (u32_1133a0)__p0; u32_1133a0 b = (u32_1133a0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1133a0, &TypeB_1133a0, 0)) {
        hulkfight::ai::SemaphoreWaitAction* q = Alloc(0x28);
        if (q)
            return (int)(((SemaphoreWaitAction_nv_1133a0*)(q))->Init(this, p));
    }
    return (int)(0);
}
