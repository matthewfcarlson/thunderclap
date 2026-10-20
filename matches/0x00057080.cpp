#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void* __cdecl Allocate(unsigned int);
extern "C" int AxisVtable_57080;
class CAxisSpeedCondition_57080 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    int a, b, c, d, e;
    void Initialize(int);
};

template <> void* fight::ConditionFactoryTemplate<CAxisSpeedCondition>::vfunc_5() {
    CAxisSpeedCondition_57080* p = (CAxisSpeedCondition_57080*)Allocate(0x18);
    if (p) {
        p->Initialize(0);
        p->c = 0;
        *(hulk_intptr*)p = (hulk_intptr)&AxisVtable_57080;
        p->d = 4;
        p->e = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
