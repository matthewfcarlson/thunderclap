// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_157450;
extern int TypeA_157450;
extern int TypeB_157450;
struct HitOrientToPushbackAction_nv_157450 {
    u32_157450 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::HitOrientToPushbackAction* Alloc(int);

int hulkfight::motion::HitOrientToPushbackTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_157450 a = (u32_157450)__p0; u32_157450 b = (u32_157450)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_157450, &TypeB_157450, 0)) {
        hulkfight::motion::HitOrientToPushbackAction* q = Alloc(0x28);
        if (q)
            return (int)(((HitOrientToPushbackAction_nv_157450*)(q))->Init(this, p));
    }
    return (int)(0);
}
