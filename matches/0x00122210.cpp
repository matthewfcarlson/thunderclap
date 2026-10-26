// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_122210;
extern int TypeA_122210;
extern int TypeB_122210;
struct StrafeCircleHBAction_nv_122210 {
    u32_122210 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::StrafeCircleHBAction* Alloc(int);

hulk_intptr hulkfight::ai::StrafeCircleHBTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_122210 a = (u32_122210)__p0; u32_122210 b = (u32_122210)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_122210, &TypeB_122210, 0)) {
        hulkfight::ai::StrafeCircleHBAction* q = Alloc(0x28);
        if (q)
            return (int)(((StrafeCircleHBAction_nv_122210*)(((hulkfight::ai::StrafeCircleHBAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}
