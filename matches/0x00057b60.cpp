#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f70a0[];
void* __cdecl Allocate(unsigned int);
struct CCollisionPushbackYCondition_57b60 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    int pad0;
    int pad1;
    int a;
    int b;
};
struct Initializer_57b60 {
    void init(int);
};

template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackYCondition>::vfunc_5() {
    CCollisionPushbackYCondition_57b60* p = (CCollisionPushbackYCondition_57b60*)Allocate(0x14);
    if (p) {
        ((Initializer_57b60*)p)->init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f70a0);
        p->a = 3;
        p->b = 0;
    } else
        return (void*)((CCollisionPushbackYCondition_57b60*)0);
    return (void*)(p);
}
