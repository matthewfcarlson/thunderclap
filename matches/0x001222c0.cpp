// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_1222c0;
extern int TypeA_1222c0;
extern int TypeB_1222c0;
struct Result_1222c0 {
    u32_1222c0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_1222c0* Alloc(int);

int hulkfight::ai::StrafeLateralHBTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_1222c0 a = (u32_1222c0)__p0; u32_1222c0 b = (u32_1222c0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1222c0, &TypeB_1222c0, 0)) {
        Result_1222c0* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
