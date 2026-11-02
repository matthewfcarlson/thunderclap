// Same code shape as 0x00051fe0 (propagated; names are from that function)
#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* CFightNodeConditionVtable;
struct CFightNodeCondition_52280 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init();
};

template <> void* fight::ConditionFactoryTemplate<CGrappleFightNodeCondition>::vfunc_5() {
    CFightNodeCondition_52280* p = (CFightNodeCondition_52280*)FUN_0008d690(0x1c);
    if (p) {
        p->Init();
        *(void**)p = &CFightNodeConditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
