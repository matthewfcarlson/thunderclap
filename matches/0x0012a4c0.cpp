#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040fd94[];
extern void* __cdecl Alloc(unsigned int);
class InitObj_12a4c0 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_5() {
    void* p = Alloc(0x14);
    if (p) {
        ((InitObj_12a4c0*)p)->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040fd94);
        *(unsigned int*)((char*)p + 0x0c) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
