#include "gen/fight.h"

extern "C" char DAT_003f6fa4[];
typedef unsigned int u32_578b0;
extern void* __cdecl FUN_0008d690(unsigned int);
struct CCollisionHitLocationCondition_578b0 {
    virtual void a();
    virtual void b();
    virtual void c();
    int pad;
    int x;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<CCollisionHitLocationCondition>::vfunc_5() {
    CCollisionHitLocationCondition_578b0* p = (CCollisionHitLocationCondition_578b0*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(u32_578b0*)p = ((int)DAT_003f6fa4);
        ((u32_578b0*)p)[3] = 2;
        ((u32_578b0*)p)[4] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
