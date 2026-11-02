#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040fd94[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class InitObj_12a4c0 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_5() {
    void* p = FUN_0008d690(0x14);
    if (p) {
        ((InitObj_12a4c0*)p)->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040fd94);
        *(unsigned int*)((char*)p + 0x0c) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
