#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041918c[];
class Condition_18b860 {
  public:
    Condition_18b860(int);
};
class PropGrabbableIsThrownCondition_18b860 : public Condition_18b860 {
  public:
    PropGrabbableIsThrownCondition_18b860(int);
    char pad[12];
    char flag;
};
void* __cdecl Alloc(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_5() {
    PropGrabbableIsThrownCondition_18b860* p = (PropGrabbableIsThrownCondition_18b860*)Alloc(16);
    if (p) {
        p->PropGrabbableIsThrownCondition_18b860::PropGrabbableIsThrownCondition_18b860(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041918c);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
