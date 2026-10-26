#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_1131c0;
extern int TypeA_1131c0;
extern int TypeB_1131c0;
struct TokenSupressAction_nv_1131c0 {
    u32_1131c0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::TokenSupressAction* Alloc(int);

hulk_intptr hulkfight::ai::TokenSupressTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1131c0 a = (u32_1131c0)__p0; u32_1131c0 b = (u32_1131c0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1131c0, &TypeB_1131c0, 0)) {
        hulkfight::ai::TokenSupressAction* q = Alloc(0x28);
        if (q)
            return (int)(((TokenSupressAction_nv_1131c0*)(((hulkfight::ai::TokenSupressAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
