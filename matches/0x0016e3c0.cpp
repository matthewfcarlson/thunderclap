#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004169d8[];
struct ConditionFactoryTemplate_nv_16e3c0 {
    void Init(int);
};
extern void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_5() {
    fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>* p = (fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>*)FUN_0008d690(0x14);
    if (p) {
        ((ConditionFactoryTemplate_nv_16e3c0*)(p))->Init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004169d8);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
