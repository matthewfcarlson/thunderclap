#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00416918[];
struct Obj_16dfc0 {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
extern Obj_16dfc0* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_5() {
    Obj_16dfc0* p = FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00416918);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
