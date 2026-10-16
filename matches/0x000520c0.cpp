#include "gen/fight.h"

extern "C" char DAT_003f8504[];
typedef unsigned int u32_520c0;
struct CFightNodeParentCondition_520c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void InitMe();
};
void* __cdecl Allocate(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CFightNodeParentCondition>::vfunc_5() {
    CFightNodeParentCondition_520c0* p = (CFightNodeParentCondition_520c0*)Allocate(0x20);
    if (p) {
        p->InitMe();
        *(u32_520c0*)p = ((int)DAT_003f8504);
        return (void*)(p);
    }
    return (void*)(0);
}
