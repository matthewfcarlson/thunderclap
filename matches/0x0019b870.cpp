// Same code shape as 0x00119fb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_19b870;
extern int TypeA_19b870, TypeB;
struct Params_19b870 {
    int Init(hulkfight::motion::AccuracyLatencyTrack*, void*);
};
extern int IsKindOf(void*, int, int*, int*, int);
extern void* Alloc(hulk_uintptr);

hulk_intptr hulkfight::motion::AccuracyLatencyTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_19b870 a = (u32_19b870)__p0; u32_19b870 b = (u32_19b870)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_19b870, &TypeB, 0)) {
        Params_19b870* q = (Params_19b870*)Alloc(0x34);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}
