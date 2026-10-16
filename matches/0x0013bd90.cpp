// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13bd90;
extern int TypeA_13bd90;
extern int TypeB_13bd90;
struct Result_13bd90 {
    u32_13bd90 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_13bd90* Alloc(int);

int hulkfight::motion::AnimationTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_13bd90 a = (u32_13bd90)__p0; u32_13bd90 b = (u32_13bd90)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13bd90, &TypeB_13bd90, 0)) {
        Result_13bd90* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
