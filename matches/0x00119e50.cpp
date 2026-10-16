// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_119e50;
extern int TypeA_119e50;
extern int TypeB_119e50;
struct Result_119e50 {
    u32_119e50 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_119e50* Alloc(int);

int hulkfight::ai::MotionTargetTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_119e50 a = (u32_119e50)__p0; u32_119e50 b = (u32_119e50)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_119e50, &TypeB_119e50, 0)) {
        Result_119e50* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
