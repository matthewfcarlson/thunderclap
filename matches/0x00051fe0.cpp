#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* CFightNodeConditionVtable;
struct CFightNodeCondition_51fe0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init();
};

template <> void* fight::ConditionFactoryTemplate<CFightNodeCondition>::vfunc_5() {
    CFightNodeCondition_51fe0* p = (CFightNodeCondition_51fe0*)FUN_0008d690(0x1c);
    if (p) {
        p->Init();
        *(void**)p = &CFightNodeConditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
