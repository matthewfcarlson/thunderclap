#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f6fec[];
class CCollisionPushbackDirectionCondition_57a00 {
  public:
    hulk_intptr pad0;
    int pad4;
    int pad8;
    int mA;
    int mB;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackDirectionCondition>::vfunc_5() {
    CCollisionPushbackDirectionCondition_57a00* p = (CCollisionPushbackDirectionCondition_57a00*)FUN_0008d690((int)sizeof(CCollisionPushbackDirectionCondition_57a00));
    if (p) {
        p->Init(0);
        p->pad0 = ((hulk_intptr)DAT_003f6fec);
        p->mA = 0;
        p->mB = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)((void*)0);
}
