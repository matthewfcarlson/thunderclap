// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_12c970;
extern int TypeA_12c970;
extern int TypeB_12c970;
struct Result_12c970 {
    u32_12c970 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_12c970* Alloc(int);

int hulkfight::ai::ThreatBallTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_12c970 a = (u32_12c970)__p0; u32_12c970 b = (u32_12c970)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_12c970, &TypeB_12c970, 0)) {
        Result_12c970* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
