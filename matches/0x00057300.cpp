#include "gen/fight.h"

extern "C" char DAT_003f9230[];
void* __cdecl Alloc(unsigned int);
class CButtonPressCondition_57300 {
  public:
    CButtonPressCondition_57300();
};

template <> void* fight::ConditionFactoryTemplate<CButtonPressCondition>::vfunc_5() {
    CButtonPressCondition_57300* p = (CButtonPressCondition_57300*)Alloc(0x20);
    if (p) {
        p->CButtonPressCondition_57300::CButtonPressCondition_57300();
        *(int*)p = ((int)DAT_003f9230);
        return (void*)(p);
    }
    return (void*)(0);
}
