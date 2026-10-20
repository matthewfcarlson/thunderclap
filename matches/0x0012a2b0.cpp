#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040fd14[];
extern void* __cdecl Alloc(unsigned int);
class TargetDirectionYCondition_12a2b0 {
  public:
    int v0;
    int pad4;
    int pad8;
    int x;
    int y;
};
class Base_12a2b0 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionYCondition>::vfunc_5() {
    TargetDirectionYCondition_12a2b0* p = (TargetDirectionYCondition_12a2b0*)Alloc(0x14);
    if (p) {
        ((Base_12a2b0*)p)->Init(0);
        p->v0 = ((hulk_intptr)DAT_0040fd14);
        p->x = 0;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
