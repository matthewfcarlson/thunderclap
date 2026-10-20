#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00413f70[];
void* __cdecl Alloc(hulk_uintptr);
struct Obj_158f40 {
    hulk_uintptr vt;
    int pad[2];
    int a;
    int b;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_5() {
    Obj_158f40* p = (Obj_158f40*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00413f70);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
