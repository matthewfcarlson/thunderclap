#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f9754[];
class CCollisionFlagCondition_58e50 {
  public:
    hulk_intptr vf;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CCollisionFlagCondition>::vfunc_5() {
    CCollisionFlagCondition_58e50* p = (CCollisionFlagCondition_58e50*)FUN_0008d690(0x18);
    if (p) {
        p->Init();
        p->vf = ((hulk_intptr)DAT_003f9754);
        return (void*)(p);
    }
    return (void*)(0);
}
