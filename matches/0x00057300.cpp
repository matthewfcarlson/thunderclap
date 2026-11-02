#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f9230[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class CButtonPressCondition_57300 {
  public:
    CButtonPressCondition_57300();
};

template <> void* fight::ConditionFactoryTemplate<CButtonPressCondition>::vfunc_5() {
    CButtonPressCondition_57300* p = (CButtonPressCondition_57300*)FUN_0008d690(0x20);
    if (p) {
        p->CButtonPressCondition_57300::CButtonPressCondition_57300();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f9230);
        return (void*)(p);
    }
    return (void*)(0);
}
