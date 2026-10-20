#include "compat/ptr.h"
#include "gen/fight.h"

class InActiveCondition_114440 {
  public:
    hulk_uintptr vptr;
    char pad4[8];
    int fieldC;
    char field10;
    void Init(int);
};
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_InActiveVftable;

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::InActiveCondition>::vfunc_5() {
    InActiveCondition_114440* p = (InActiveCondition_114440*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (hulk_uintptr)&g_InActiveVftable;
        p->fieldC = 0;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
