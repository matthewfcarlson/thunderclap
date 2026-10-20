#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f9098[];
class CAxisDownCondition_56e40 {
  public:
    CAxisDownCondition_56e40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CAxisDownCondition>::vfunc_5() {
    CAxisDownCondition_56e40* p = (CAxisDownCondition_56e40*)FUN_0008d690(0x20);
    if (p) {
        p->CAxisDownCondition_56e40::CAxisDownCondition_56e40();
        *(void**)p = (void*)((hulk_intptr)DAT_003f9098);
        return (void*)(p);
    }
    return (void*)(0);
}
