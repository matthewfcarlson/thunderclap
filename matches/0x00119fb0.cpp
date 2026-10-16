#include "gen/hulkfight.h"

typedef unsigned int u32_119fb0;
extern int TypeA_119fb0, TypeB;
struct Params_119fb0 {
    int Init(hulkfight::ai::MotionBoostTrack*, void*);
};
extern int IsKindOf(void*, int, int*, int*, int);
extern void* Alloc(unsigned int);

int hulkfight::ai::MotionBoostTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_119fb0 a = (u32_119fb0)__p0; u32_119fb0 b = (u32_119fb0)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_119fb0, &TypeB, 0)) {
        Params_119fb0* q = (Params_119fb0*)Alloc(0x34);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}
