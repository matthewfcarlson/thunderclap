#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_1891f0;
struct Track_1891f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual u32_1891f0 v10(u32_1891f0 a, u32_1891f0 b, u32_1891f0 c);
};
struct Obj_1891f0 {
    u32_1891f0 Init(hulkfight::motion::BallAndChainReturnTrack*, hulk_uintptr);
};
extern int IsType(void*, int, hulk_intptr, hulk_intptr, int);
extern void* Alloc(hulk_uintptr);
extern int typeA_1891f0, typeB;

hulk_intptr hulkfight::motion::BallAndChainReturnTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1891f0 a = (u32_1891f0)__p0; u32_1891f0 b = (u32_1891f0)__p1; hulk_uintptr c = (u32_1891f0)__p2;

    if (IsType((void*)c, 0, (hulk_intptr)&typeB, (hulk_intptr)&typeA_1891f0, 0)) {
        Obj_1891f0* p = (Obj_1891f0*)Alloc(0x48);
        if (p)
            return (int)(p->Init(this, c));
    }
    return (int)(0);
}
