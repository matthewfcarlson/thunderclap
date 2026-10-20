// Same code shape as 0x00119fb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_138fc0;
extern int TypeA_138fc0, TypeB;
struct Params_138fc0 {
    int Init(hulkfight::motion::BounceTrack*, void*);
};
extern int IsKindOf(void*, int, int*, int*, int);
extern void* Alloc(hulk_uintptr);

int hulkfight::motion::BounceTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_138fc0 a = (u32_138fc0)__p0; u32_138fc0 b = (u32_138fc0)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_138fc0, &TypeB, 0)) {
        Params_138fc0* q = (Params_138fc0*)Alloc(0x34);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}
