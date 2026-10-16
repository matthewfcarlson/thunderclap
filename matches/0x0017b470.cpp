// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b470;
extern int TypeA_17b470;
extern int TypeB_17b470;
struct Result_17b470 {
    u32_17b470 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_17b470* Alloc(int);

int hulkfight::motion::PushOutTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17b470 a = (u32_17b470)__p0; u32_17b470 b = (u32_17b470)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_17b470, &TypeB_17b470, 0)) {
        Result_17b470* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
