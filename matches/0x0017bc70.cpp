// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17bc70;
extern int TypeA_17bc70;
extern int TypeB_17bc70;
struct Result_17bc70 {
    u32_17bc70 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_17bc70* Alloc(int);

int hulkfight::motion::RestPoseTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17bc70 a = (u32_17bc70)__p0; u32_17bc70 b = (u32_17bc70)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_17bc70, &TypeB_17bc70, 0)) {
        Result_17bc70* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
