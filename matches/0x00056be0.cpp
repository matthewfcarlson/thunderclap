#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f6ed8[];
extern void* __cdecl Alloc(hulk_uintptr);
class CAxisArcCondition_56be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<CAxisArcCondition>::vfunc_5() {
    CAxisArcCondition_56be0* p = (CAxisArcCondition_56be0*)Alloc(0x20);
    if (p) {
        p->Init(0);
        *(int*)((char*)p + 0xc) = 0;
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f6ed8);
        *(int*)((char*)p + 0x18) = 5;
        *(unsigned int*)((char*)p + 0x1c) = 0x3fc90fdb;
        *(int*)((char*)p + 0x10) = 0;
        *(unsigned int*)((char*)p + 0x14) = 0x3f000000;
        return (void*)(p);
    } else {
        return (void*)((CAxisArcCondition_56be0*)0);
    }
}
