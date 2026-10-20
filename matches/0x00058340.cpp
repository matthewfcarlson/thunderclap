#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7304[];
struct CLuaNumberCondition_58340 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    void init(int);
};
extern void* __cdecl Allocate(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CLuaNumberCondition>::vfunc_5() {
    CLuaNumberCondition_58340* p = (CLuaNumberCondition_58340*)Allocate(0x54);
    if (p) {
        p->init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7304);
        *(unsigned int*)((char*)p + 0xc) = 2;
        *(unsigned int*)((char*)p + 0x50) = 0;
        *((unsigned char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
