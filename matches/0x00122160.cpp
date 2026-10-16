// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_122160;
extern int TypeA_122160;
extern int TypeB_122160;
struct Result_122160 {
    u32_122160 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_122160* Alloc(int);

int hulkfight::ai::StrafeCircleTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_122160 a = (u32_122160)__p0; u32_122160 b = (u32_122160)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_122160, &TypeB_122160, 0)) {
        Result_122160* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
