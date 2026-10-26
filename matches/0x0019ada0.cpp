// Same code shape as 0x00119fb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_19ada0;
extern int TypeA_19ada0, TypeB;
struct Params_19ada0 {
    int Init(hulkfight::motion::FireProjectileTrack*, void*);
};
extern int IsKindOf(void*, int, int*, int*, int);
extern void* Alloc(hulk_uintptr);

hulk_intptr hulkfight::motion::FireProjectileTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_19ada0 a = (u32_19ada0)__p0; u32_19ada0 b = (u32_19ada0)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_19ada0, &TypeB, 0)) {
        Params_19ada0* q = (Params_19ada0*)Alloc(0x34);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}
