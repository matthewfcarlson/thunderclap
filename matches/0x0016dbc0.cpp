#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00416838[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetHealthPercentCondition_16dbc0 {
  public:
    void Init(int);
    unsigned int vt;
    int pad[2];
    int a, b;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_5() {
    TargetHealthPercentCondition_16dbc0* p = (TargetHealthPercentCondition_16dbc0*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00416838);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
