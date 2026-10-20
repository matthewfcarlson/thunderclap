#include "compat/ptr.h"
#include "gen/fight.h"

class CClimbableCondition_575f0 {
  public:
    int vt;
    void Init(int);
    int a;
    int b;
    int c;
    int d;
    char e;
};
extern int climbVftable;
extern void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CClimbableCondition>::vfunc_5() {
    CClimbableCondition_575f0* p = (CClimbableCondition_575f0*)FUN_0008d690(0x18);
    if (p) {
        p->Init(0);
        p->vt = (hulk_intptr)&climbVftable;
        p->c = 0;
        p->d = 0x3e860a92;
        p->e = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
