// Same code shape as 0x00119fb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_17be60;
extern int TypeA_17be60, TypeB;
struct Params_17be60 {
    int Init(hulkfight::motion::MomentumXZAddTrack*, void*);
};
extern int IsKindOf(void*, int, int*, int*, int);
extern void* Alloc(hulk_uintptr);

int hulkfight::motion::MomentumXZAddTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17be60 a = (u32_17be60)__p0; u32_17be60 b = (u32_17be60)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_17be60, &TypeB, 0)) {
        Params_17be60* q = (Params_17be60*)Alloc(0x34);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}
