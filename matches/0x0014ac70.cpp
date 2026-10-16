// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_14ac70;
extern int TypeA_14ac70;
extern int TypeB_14ac70;
struct Result_14ac70 {
    u32_14ac70 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_14ac70* Alloc(int);

int hulkfight::motion::GrappleStruggleTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_14ac70 a = (u32_14ac70)__p0; u32_14ac70 b = (u32_14ac70)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_14ac70, &TypeB_14ac70, 0)) {
        Result_14ac70* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
