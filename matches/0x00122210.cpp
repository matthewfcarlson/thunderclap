// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_122210;
extern int TypeA_122210;
extern int TypeB_122210;
struct StrafeCircleHBAction_nv_122210 {
    u32_122210 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::StrafeCircleHBAction* Alloc(int);

int hulkfight::ai::StrafeCircleHBTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_122210 a = (u32_122210)__p0; u32_122210 b = (u32_122210)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_122210, &TypeB_122210, 0)) {
        hulkfight::ai::StrafeCircleHBAction* q = Alloc(0x28);
        if (q)
            return (int)(((StrafeCircleHBAction_nv_122210*)(q))->Init(this, p));
    }
    return (int)(0);
}
