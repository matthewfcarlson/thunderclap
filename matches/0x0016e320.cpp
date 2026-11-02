#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004169b8[];
struct Obj_16e320 {
    hulk_intptr vf;
    char pad[8];
    unsigned char flag;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::ThinkingCondition>::vfunc_5() {
    Obj_16e320* p = (Obj_16e320*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        p->vf = ((hulk_intptr)DAT_004169b8);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)((Obj_16e320*)0);
}
