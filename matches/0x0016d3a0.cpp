#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00416678[];
extern void* __cdecl FUN_0008d690(hulk_uintptr);
class Temp_16d3a0 {
  public:
    virtual void V();
    char pad[8];
    int x;
    int y;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_5() {
    Temp_16d3a0* p = (Temp_16d3a0*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00416678);
        p->x = 0;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
