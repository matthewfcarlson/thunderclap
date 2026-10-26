// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_17b470;
extern int TypeA_17b470;
extern int TypeB_17b470;
struct PushOutAction_nv_17b470 {
    u32_17b470 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::PushOutAction* Alloc(int);

hulk_intptr hulkfight::motion::PushOutTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b470 a = (u32_17b470)__p0; u32_17b470 b = (u32_17b470)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_17b470, &TypeB_17b470, 0)) {
        hulkfight::motion::PushOutAction* q = Alloc(0x28);
        if (q)
            return (int)(((PushOutAction_nv_17b470*)(((hulkfight::motion::PushOutAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
