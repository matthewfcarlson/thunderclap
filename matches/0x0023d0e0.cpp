#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00428a24[];
typedef unsigned int u32_23d0e0;
struct NotCondition_23d0e0 {
    virtual void a();
    virtual void b();
    virtual void c();
};
extern void* __cdecl FUN_0008d690(hulk_uintptr);
struct Helper_23d0e0 {
    void f(int);
};

template <> void* fight::ConditionFactoryTemplate<fight::NotCondition>::vfunc_5() {
    NotCondition_23d0e0* p = (NotCondition_23d0e0*)FUN_0008d690(0xc);
    if (p) {
        ((Helper_23d0e0*)p)->f(2);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00428a24);
        return (void*)(p);
    }
    return (void*)((NotCondition_23d0e0*)0);
}
