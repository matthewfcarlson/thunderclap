#include "gen/hulkfight.h"

typedef unsigned int u32_1131c0;
extern int TypeA_1131c0;
extern int TypeB_1131c0;
struct Result_1131c0 {
    u32_1131c0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_1131c0* Alloc(int);

int hulkfight::ai::TokenSupressTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_1131c0 a = (u32_1131c0)__p0; u32_1131c0 b = (u32_1131c0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1131c0, &TypeB_1131c0, 0)) {
        Result_1131c0* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}
