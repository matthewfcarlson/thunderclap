#include "gen/fight.h"

extern void* __cdecl Allocate(unsigned int);
extern void* TargetTypeCondition_vftable[];
class Cond {
  public:
    Cond(int);
    virtual void a();
    char pad[0xc - 4];
    int x;
    int y;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_5() {
    Cond* p = (Cond*)Allocate(0x14);
    if (p) {
        p->Cond::Cond(0);
        *(void* volatile*)p = TargetTypeCondition_vftable;
        p->x = 0;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
