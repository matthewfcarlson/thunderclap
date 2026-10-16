#include "gen/fight.h"

void* __cdecl Allocate(unsigned int);
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
    CFightNodeCondition_51fe0* p = (CFightNodeCondition_51fe0*)Allocate(0x1c);
    if (p) {
        p->Init();
        *(void**)p = &CFightNodeConditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
