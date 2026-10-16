#include "gen/fight.h"

extern "C" void* __cdecl Allocate(unsigned int);
extern "C" int CondVtable;
struct Sub_59140 {
    int x;
    void Init();
};
class Cond_59140 {
  public:
    virtual void V0();
    virtual void V1();
    int a, b, c;
    Sub_59140 s;
    int pad;
    void Initialize(int);
};

template <> void* fight::ConditionFactoryTemplate<CSmartPropGrabbableNameCondition>::vfunc_5() {
    Cond_59140* p = (Cond_59140*)Allocate(0x18);
    if (p) {
        p->Initialize(0);
        *(int*)p = (int)&CondVtable;
        p->c = 0;
        p->s.Init();
        return (void*)(p);
    }
    return (void*)(0);
}
