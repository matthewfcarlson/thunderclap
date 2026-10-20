#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004141b0[];
extern "C" void* __cdecl Alloc(unsigned int);
class Cond {
  public:
    Cond(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_5() {
    Cond* p = (Cond*)Alloc(20);
    if (p) {
        p->Cond::Cond(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004141b0);
        *(unsigned int*)((char*)p + 12) = 0;
        *(unsigned int*)((char*)p + 16) = 0;
        return (void*)(p);
    }
    return (void*)((Cond*)0);
}
